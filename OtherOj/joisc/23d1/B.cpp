#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 20005;

int n;
ll MOD;
ll fac[2*N];
ll invfac[2*N];
inline ll modmul(ll a, ll b) {
	ll ret = a * b - MOD * ll(1.L / MOD * a * b);
	return ret + MOD * (ret < 0) - MOD * (ret >= (ll)MOD);
}
int fastpow(int a,ll p){
	int r = 1;	
	while(p){
		if(p&1)	r = (1LL*r*a)%MOD;
		a = (1LL*a*a)%MOD;
		p>>=1;
	}
	return r;
}

ll dp[N+2][2];
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>MOD;
	fac[0]=1;
	for(int i=1;i<=2*n+2;i++){
		fac[i] = modmul(fac[i-1],i);
	}
	invfac[2*n+2] = fastpow(fac[2*n+2],MOD-2);
	invfac[0]=1;
	for(int i=2*n+1;i>=1;i--){
		invfac[i] = modmul(invfac[i+1],(i+1));
	}
	dp[1][1]=1;
	dp[2][0]=1;
	for(int i=1;i<=n;i++){
		for(int f=0;f<2;f++){
		//	cout<<dp[i][f]<<" ";
			if(!dp[i][f]) continue;
			for(int t=0;t<2;t++){
				for(int j=0;i+j+1+!t<=n;j++){
					ll k = dp[i][f];
					/*
					if(f==0 && t==0) k = 1LL*(1LL*k*(1LL*(j+1)*(j+2)%MOD)%MOD)*(fac[2*i-3+j]*invfac[2*i-3]%MOD)%MOD;
					if(f==0 && t==1) k = 1LL*(1LL*k*(j+1)%MOD)*(fac[2*i-3+j]*invfac[2*i-3]%MOD)%MOD;
					if(f==1 && t==0) k = 1LL*(1LL*k*(1LL*(j+1)%MOD)%MOD)*(fac[2*i-2+j]*invfac[2*i-2]%MOD)%MOD;
					if(f==1 && t==1) k = 1LL*(1LL*k)*(fac[2*i-2+j]*invfac[2*i-2]%MOD)%MOD;
					*/
					if(!f || !t) k = modmul(k,(j+1));
					if(!f && !t) k = modmul(k,(j+2));
					k = modmul(k,modmul(fac[2*i-3+j+f],invfac[2*i-3+f]));
					dp[i+j+1+(!t)][t] +=k;
					dp[i+j+1+(!t)][t] -=(dp[i+j+1+(!t)][t]>=MOD)?(MOD):(0);
				}
			}
		}
		//cout<<"\n";
	}
	
	ll total = modmul(fac[2*n],invfac[n]);
	total = modmul(total,fastpow(invfac[2],n));
	
	//ll total=1;
	//for(int i=1;i<=n;i++) total = 1LL*total*(2*n-2*i+1)%MOD;
	for(int i=1;i<=n;i++){
		if(dp[i][0]) total = (total-modmul(modmul(dp[i][0],(n-i+1)),modmul(fac[i+n-3],invfac[2*i-3])))%MOD;
		if(dp[i][1]) total = (total-modmul(dp[i][1],modmul(fac[i+n-2],invfac[2*i-2])))%MOD;
		//cout<<total<<"\n";
	}
	if(total<0) total+=MOD;
	cout<<total<<"\n";
	return 0;
}



/*
dp[i][0]*fac[2*i+j-3]*invfac[2*i-3]*(j+2)*(j+1)*invfac[2] =+> dp[i+j+2][0]
dp[i][0]* =+> dp[i+j+1][1]
dp[i][1] =+> dp[i+j+2][0]
dp[i][1] =+>. dp[i+j+1][1]



*/
