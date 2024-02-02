#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
//#include<bits/extc++.h>
//__gnu_pbds
const int MOD = 998244353;
const int N = 105;
int cnt[N][N];
int dp[N][N];
int mul[N];


signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	string s;cin>>s;	
	int K = 0;			
	for(auto i : s) if(i=='0') K++;
	if(K==0){
		int g = (n*(n+1)/2);
		ll ans = 1;
		for(int i=0;i<q;i++){
			ans = ans*g%MOD;	
		}
		cout<<ans<<"\n";
		return 0;
	}
	int b = 0;
	for(int i=0;i<=K;i++) dp[i][0]=1;
	mul[0]=1;
	for(int i=1;i<=q;i++){
		for(int j=q;j>=0;j--){
			if(j) mul[j] = (mul[j-1]+mul[j]*j)%MOD;
			else mul[j] = 0 ;
		}
	}
	ll re = 1;
	for(int i=0;i<=q;i++){
		mul[i] = re*mul[i]%MOD;
		re = (re*(i+1))%MOD;
	}
	for(int l=0;l<n;l++){
		int t = b;
		for(int r=l;r<n;r++){ 
			if(s[r]=='0') t++;
			for(int k=K;k>=0;k--){
				for(int i=q;i>=0;i--){
					if(i && k>=t) dp[k][i] = (dp[k][i]+((dp[k][i-1]-((b)?(dp[b-1][i-1]):(0)))%MOD))%MOD; 
					if(dp[k][i]<0) dp[k][i]+=MOD;
				}
			}
		}
		if(s[l]=='0') b++;
	}
	ll ans = 0;	
	for(int i=0;i<=q;i++){
		ans = (ans+(1LL*mul[i]*(dp[K][i]-dp[K-1][i])%MOD))%MOD;
		if(ans<0) ans+=MOD;
	}
	cout<<ans<<"\n";
	return 0;
}
