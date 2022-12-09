#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	int q;cin>>q;	
	ll dis[n+1][n+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(i==j) dis[i][j]=  0;
			else dis[i][j]=  1e18;
		}
	}
	while(m--){
		int a,b;cin>>a>>b;
		ll c;cin>>c;
		dis[a][b] = min(c,dis[a][b]);
		dis[b][a] = min(c,dis[a][b]);
	}

	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j] = min(dis[i][k]+dis[k][j],dis[i][j]);
			}
		}
	}
	while(q--){
		int a,b;cin>>a>>b;
		cout<<((dis[a][b]>1e17)?(-1LL):(dis[a][b]))<<"\n";
	
	}
	return 0;
}
