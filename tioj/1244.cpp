#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::

const int MOD = 1e8+7;

int fac[10005];

int inv(int a){
	int p = MOD - 2;
	int r=1;
	while(p){
		if(p&1)  r = (1LL*r*a)%MOD;
		a = (1LL*a*a)%MOD;
		p>>=1;
	}
	return r;
}
int c(int n,int r){
	int ans = fac[n];
	int d = (1LL*fac[r]*fac[n-r])%MOD;
	ans = (1LL*ans*inv(d))%MOD;
	return ans;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	fac[0]=1;
	for(int i=1;i<=10004;i++){
		fac[i] = (1LL*fac[i-1]*i)%MOD;
	}
	int n;cin>>n;
	ll dp[n+1]={0};
	dp[0]=1; dp[1]=1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<i;j++){
			dp[i] += (1LL*c(i-1,j)*dp[j])%MOD;
			dp[i]%=MOD;
		}
	}
	cout<<dp[n]<<"\n";
	return 0;
}

