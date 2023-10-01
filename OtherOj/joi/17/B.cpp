#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,popcnt,sse4,abm")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
#define int ll

ll dp[3005][2];

int stop[3005];
signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,k;cin>>n>>m>>k;
	int a,b,c;cin>>a>>b>>c;
	ll T;cin>>T;
	k-=m;
	for(int i=0;i<m;i++){cin>>stop[i];stop[i]--;}
	for(int i=0;i<m-1;i++){
			ll cur = T-(stop[i]*b);
			ll l = stop[i];
			for(int j=0;j<=k;j++) dp[j][i&1] = dp[j][(i&1)^1];
			for(int j=0;j<=k;j++){
				if(cur<0) break;
				int ok = min(stop[i+1]-l , cur/a+1);
				l+=ok;
				cur-=(c*ok);
				for(int g=j;g<=k;g++){
					dp[g][i&1] = max(dp[g][i&1],dp[g-j][(i&1)^1] + l - stop[i]);
				}			
			}
		}
	cout<<dp[k][((m)&1)^1]+(((n-1)*b)<=T)-1<<"\n";
	return 0;
}
