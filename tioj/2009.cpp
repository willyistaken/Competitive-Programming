#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::

const int MOD =9;

inline int madd(int a,int b){
	a = (a+b)%MOD;
	if(a<0) a+=MOD;
	return a;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k;cin>>n>>k;
	int a[n],b[n];
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	for(int i=0;i<n;i++) {
		a[i]--;
		b[i]--;
		a[i] = madd(b[i],-a[i]);
	//	cout<<a[i]<<" ";
	}
	int prev=0;
	int	dif[n];
	for(int i=0;i<n;i++){
		dif[i] = madd(a[i],-prev);
		prev = a[i];
	//	cout<<dif[i]<<" ";
	}
	//dif[n-2]=0;
	int ans=0;
	for(int i=0;i<=n-k;i++){
		ans+=dif[i];
		if(i+k<n) dif[i+k] = madd(dif[i+k],dif[i]);
		dif[i] = madd(dif[i],-dif[i]);
	}
	for(int i=0;i<n;i++){
		if(dif[i]) {
			cout<<0<<"\n";
			return 0;
		}
	//	cout<<dif[i]<<" ";
	}
	cout<<ans<<"\n";
	return 0;
}
