#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
#define int ll
const int N = 1e6+5;
const int MOD = 1e9+7;
int fac[N];

int inv(int a){
	int p = MOD-2;
	ll r = 1;
	while(p){
		if(p&1) r = (r*a)%MOD;
		a =  (1LL*a*a)%MOD;
		p>>=1;
	}
	return r;
}

void init(){
	fac[0]=1;
	for(int i=1;i<N;i++) fac[i]=(1LL*fac[i-1]*i)%MOD;
}
signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	init();
	int n,h;cin>>n>>h;				
	ll dp[h+1][2];
	dp[0][1]=0;
	dp[0][0]=fac[n];
	int sum[h+1];
	sum[0]	=0;
	for(int i=1;i<=h;i++){
		int a;cin>>a;
		sum[i]=sum[i-1]+a;
	}
	//cout<<dp[0][0]<<" "<<dp[0][1]<<"\n";
	for(int i=1;i<=h;i++){
		dp[i][0]=0;
		dp[i][1]=0;
		for(int j=1;j<=i;j++){
			ll g = ((((dp[i-j][1]*inv(fac[n-sum[i-j]]))%MOD)*fac[sum[i]-sum[i-j]]%MOD)*fac[n-sum[i]])%MOD;
			dp[i][0]+=g;
			g = ((((dp[i-j][0]*inv(fac[n-sum[i-j]]))%MOD)*fac[sum[i]-sum[i-j]]%MOD)*fac[n-sum[i]])%MOD;
			dp[i][1]+=g;
			dp[i][0]%=MOD;
			dp[i][1]%=MOD;
		}
		//cout<<dp[i][0]<<" "<<dp[i][1]<<"\n";
	}
	ll osum = 0;
	ll esum=0;
	for(int i=0;i<=h;i++){
		osum+=dp[i][1];
		esum+=dp[i][0];
	}
	cout<<esum-osum<<"\n";
	return 0;
}
