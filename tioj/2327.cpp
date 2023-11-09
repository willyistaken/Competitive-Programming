#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

int a,b,x,y,N,M;
int bpN[1005];
int bpM[1005];
vector<int> mul(vector<int> &va,vector<int> &vb){
	vector<ll> ret(y+1,0);
	for(int i=0;i<=y;i++){
		for(int j=0;j<=y;j++){
			if(i+j<y){
				ret[i+j]+=1LL*va[i]*vb[j];
			}else{
				ret[y]=(ret[y]+(1LL*bpN[i+j-y]*((1LL*va[i]*vb[j])%N))%N)%N;
			}
			
		}
		for(int j=0;j<y;j++){
			ret[j+1]+=ret[j]/b;
			ret[j]%=b;
		}
		ret[y]%=N;
	}
	ret[y]%=N;
	vector<int> ans;
	for(int i=0;i<=y;i++) ans.push_back(ret[i]);
	return ans;
}

vector<int> pow(vector<int> a,int p){
	vector<int> ret(y+1);
	ret[0]=1;
	while(p){
		if(p&1) ret = mul(ret,a);
		a = mul(a,a);
		p>>=1;
	}
	return ret;
}

int ipow(int a,int p,int MOD){
	ll r = 1;
	while(p){
		if(p&1) r = (r*a)%MOD;
		a = (1LL*a*a)%MOD;
		p>>=1;
	}
	return r;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>a>>b>>x>>y>>N>>M;
	if(b==1){
		cout<<ipow(a,x,N)<<" "<<0<<"\n";
		return 0;
	}
	bpN[0]=1;
	bpM[0]=1;
	for(int i=1;i<=y;i++){
		bpN[i] = (bpN[i-1]*b)%N;
		bpM[i] = (bpM[i-1]*b)%M;
	}
	vector<int> va(y+1);
	for(int i=0;i<y;i++){
		va[i] = a%b;
		a/=b;
	}
	va[y] = a%N;
	vector<int> ret = pow(va,x);
	ll ans = 0;
	for(int i=0;i<y;i++){
		ans=(ans+(1LL*ret[i]*bpM[i])%M)%M;
	}
	cout<<ret[y]<<" "<<ans<<"\n";
	return 0;
}
