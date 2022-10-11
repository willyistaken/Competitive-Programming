#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::
int n;
const int MOD = 1e9+7;
struct matrix{
	vector<vector<int> > arr;
	matrix(): arr(vector<vector<int>>(n+1, vector<int>(n+1,0))){}
	void print(){
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++) cout<<arr[i][j]<<" ";
			cout<<"\n";
		}
		cout<<"\n";
	}
		
};

matrix mul(const matrix &a,const matrix &b){
	matrix result;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=i;j++){
			for(int k=0;k<=i;k++){
				result.arr[i][j] += (1LL*a.arr[k][j]*b.arr[i][k])%MOD;
				result.arr[i][j] = (result.arr[i][j]>MOD)?(result.arr[i][j]-MOD):(result.arr[i][j]);
			}
		}
	}

	return result;
}

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	ll t;cin>>t;
	int MAXC = __lg(t)+3;
	matrix pow2[MAXC];
	for(int i=0;i<=n;i++){
		pow2[0].arr[i][i]=1;
	}
	pow2[1] = pow2[0];
	pow2[1].arr[1][0]=1;
	matrix cur = mul(pow2[1],pow2[0]);
	for(int i=2;i<MAXC;i++){
		pow2[i] = cur;
		if(i<=n){
			for(int k=0;k<=n;k++){
				pow2[i].arr[i][k]+=pow2[i].arr[i-1][k];
				pow2[i].arr[i][k] = (pow2[i].arr[i][k]>MOD)?(pow2[i].arr[i][k]-MOD):(pow2[i].arr[i][k]);
			}
		}
		cur = mul(pow2[i],cur);
	}
	matrix result = pow2[0];
	for(int i=MAXC-1;i>=0;i--){
		if((t>>i)&1){
			result = mul(result,pow2[i+1]);
		}
	}
	//result.print();
	int arr[n+1];
	for(int i=1;i<=n;i++) cin>>arr[i];
	arr[0]=1;
	for(int i=1;i<=n;i++){
		ll ans=0;
		for(int k=0;k<=n;k++){
			ans+=(1LL*result.arr[i][k]*arr[k])%MOD;
			ans = (ans>MOD)?(ans-MOD):(ans);
		}
		cout<<ans<<" ";
	}
	cout<<"\n";
	return 0;
}



/*Observation:
	if t is a power of 2, the t=2^n transpose of decompose matrix  is the mul of transpose of  2^n-1 matrix
	if decompose from a high bit first then we can mul together matrixs 
 */


/* Reflection:
	most of the problem has a central "action" , try to find the property the action has(like combination,transpose,and other things)
 */
