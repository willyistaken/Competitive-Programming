#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N  =2005;
ll dp[N];
ll v[N];
ll b[N];
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,k,t;cin>>n>>m>>k>>t;	
	string s;cin>>s;
	for(int i=1;i<=n;i++){
		cin>>v[i];
		if(s[i-1]=='0') v[i]+=t;
	}
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int out=0;out<k;out++){
		for(int i=n;i>=0;i--){
			dp[i] = 1e17;
			if(i>=m){
			ll cost = 0;		
			cost+=b[i]+v[i];
			priority_queue<ll> pq;
			for(int j=i-1;j>=0;j--){
				if(j<=i-m){
					dp[i] = min(dp[i],dp[j]+cost);
				}
				cost+=v[j];
				pq.push(v[j]);
				if(pq.size()>(m-1)) {
					cost-=pq.top();
					pq.pop();
				}
			}
			}
		}
	}
	ll ans = 1e18; 
	for(int i=1;i<=n;i++) ans = min(ans,dp[i]);
	cout<<ans<<"\n";

	return 0;
}
