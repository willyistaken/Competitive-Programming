#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

ll dpl[205][205][205];
ll dpr[205][205][205];


/*

dpl[i][j][k] = min(dpl[i+1][j][k-1]+x])




*/
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n,L;
	cin>>n>>L;	
	ll x[n+2]={0};
	ll t[n+2]={0};
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++) cin>>t[i];
	x[n+1]=L;
	for(int l=0;l<=n+1;l++){
		for(int r=0;r<=n+1;r++){
			for(int k=0;k<=n;k++){
				dpl[l][r][k]=1e17;
				dpr[l][r][k]=1e17;
			}
		}
	}
	dpl[0][n+1][0]=0;
	dpr[0][n+1][0]=0;
	for(int l=0;l<n;l++){
		for(int r=n+1;r>=l+2;r--){
			for(int k=0;k<=n;k++){
				ll ti = min(dpl[l][r][k]+x[l+1]-x[l],dpr[l][r][k]+L-x[r]+x[l+1]);
				dpl[l+1][r][k+(ti<=t[l+1])] = min(dpl[l+1][r][k+(ti<=t[l+1])],ti);
				ti = min(dpl[l][r][k]+L-x[r-1]+x[l],dpr[l][r][k]+x[r]-x[r-1]);
				dpr[l][r-1][k+(ti<=t[r-1])] = min(dpr[l][r-1][k+(ti<=t[r-1])],ti);
			}
		}
	}
	int ans = 0;
	for(int i=0;i<=n+1;i++){
		for(int j=0;j<=n+1;j++){
			for(int k=0;k<=n;k++){
				//cout<<dpl[i][j][k]<<":"<<i<<","<<j<<","<<k<<"\n";
				if(dpl[i][j][k]<1e17) ans = max(ans,k);
				if(dpr[i][j][k]<1e17) ans = max(ans,k);
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
