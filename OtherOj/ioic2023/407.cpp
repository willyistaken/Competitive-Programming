#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	int Q;cin>>Q;
	if(Q!=1){
		return 0;
	}
	ll a[n+1];
	ll b[m+1];
	a[0]=0;
	b[0]=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	for(int i=1;i<=n;i++) a[i]+=a[i-1];
	for(int j=1;j<=m;j++) b[j]+=b[j-1];
	int p,q,r,s;cin>>p>>q>>r>>s;	
	r-=p;
	s-=q;
	ll start = a[p]+b[q];
	ll dp[r+1][s+1]={{0}};
	dp[0][0]=start;
	if(start<0){
		cout<<-1<<"\n";
		return 0;
	}
	for(int i=0;i<=r;i++){
		for(int j=0;j<=s;j++){
			if(i==0 && j==0) continue;
			ll f,s;
			if(!i || (dp[i-1][j]<0 || a[p+i]+b[q+j]<0)) f = 1e15;
			else f = max(dp[i-1][j],a[p+i]+b[q+j]);
			if(!j || (dp[i][j-1]<0 || a[p+i]+b[q+j]<0)) s = 1e15;
			else s = max(dp[i][j-1],a[p+i]+b[q+j]);
			dp[i][j]= min(f,s);
			if(dp[i][j]>=1e14) dp[i][j]=-1;
		//	cout<<dp[i][j]<<" ";
		}
		//cout<<"\n";
	}
	if(dp[r][s]<0) cout<<-1<<"\n";
	else cout<<dp[r][s]<<"\n";
	return 0;
}
