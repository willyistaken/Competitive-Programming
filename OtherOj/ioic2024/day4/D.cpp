#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


const int MOD = 998244353;
const int N = 5005;
int fac[N];

int pow(int a,int p){
	ll r = 1;
	while(p){
		if(p&1) r = (r*a)%MOD; 
		a = (1LL*a*a)%MOD;
		p>>=1;
	}
	return r;
}
int inv[N];
int dp[N][N];
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	fac[0]=1;
	for(int i=1;i<N;i++){
		fac[i] = (1LL*fac[i-1]*i)%MOD;
	}
	for(int i=1;i<N;i++){
		inv[i] = pow(i,MOD-2);
	}
	int ncnt = 0;	
	vector<int> arr(n); 
	map<int,int> s;
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<n;i++){
		ncnt+=(arr[i]==-1);
		if(arr[i]>0){
			s[arr[i]]++;
		}
	}
	for(auto i : s){
		if(i.second>i.first){
			cout<<0<<"\n";
			return 0;
		}
	}
	ll allcnt = fac[ncnt];
	for(auto i : s)	{
		allcnt = allcnt*pow(fac[i.first-i.second],MOD-2)%MOD;
		ncnt-=i.first-i.second;	
	}
	if(ncnt<0){
		cout<<0<<"\n";
		return 0;
	}
	allcnt = allcnt*pow(fac[ncnt],MOD-2)%MOD;
	dp[0][0]=1;
	for(int i=0;i<=ncnt;i++){
		for(int j=1;j<=ncnt;j++){
			if(!s.count(j) && i-j>=0) dp[i][j] =(1LL*dp[i-j][j-1]*inv[j])%MOD;
			dp[i][j] = (dp[i][j]+dp[i][j-1])%MOD;
		}

	}
	ll ans = 1LL*fac[ncnt]*dp[ncnt][ncnt]%MOD;
	for(auto i : s)	{
		ans = ans*fac[i.first-1]%MOD;
	}
	ans = ans*allcnt%MOD; 
	cout<<ans<<"\n";
	return 0;
}
