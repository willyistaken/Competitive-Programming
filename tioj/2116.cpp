#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


/*
	for a prime P^g

	iter k times is sum{C(k+i,i)P^(g-i)}


 */
int n,K;
const int N = 1e6+1;
const int MOD = 1e9+7;

int inv(int x){
	int p = MOD - 2;
	ll r = 1;
	while(p){
		if(p&1) r = (x*r)%MOD;
		x = (1LL*x*x)%MOD;
		p>>=1;
	}
	return r;
}
int ans[N];
void init(){
	ans[1]=1;
	for(int i=2;i<N;i++){
		if(ans[i]){
			int p = ans[i];
			int k = i;
			int g = 0;
			while(k%p==0){
				g++;
				k/=p;
			}
			if(k==1){
				int f = i;		
				ans[i]=0;
				ll C = 1;
				for(int b=0;b<g+1;b++){
					ans[i]+=(1LL*C*f)%MOD;
					ans[i]%=MOD;
					f/=p;
					C = (C*(K+b))%MOD;
					C = (C*inv(b+1))%MOD;
				}
			}else{
				ans[i] = (1LL*ans[k]*ans[i/k])%MOD;
			}
		}else{
			ans[i]=i+K;
			for(int j=2*i;j<N;j+=i) ans[j]=i;
		}
		//cout<<i<<" "<<ans[i]<<"\n";
	}
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>K;
	init();								
	//for(int i=1;i<N;i++) cout<<i<<":"<<ans[i]<<"\n";
	ll sum = 0;
	for(int i=0;i<n;i++){
		int a;cin>>a;		
		sum+=ans[a];
		sum%=MOD;
	}
	cout<<sum<<"\n";

	return 0;
}

