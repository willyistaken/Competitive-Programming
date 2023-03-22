#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


int n;

int side[105][105];
ll dis[105][105];


void solve(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>side[i][j];
			if(!side[i][j] && i!=j) side[i][j] = 1e9;
			dis[i][j] = side[i][j];
		}
	}
	ll ans = 1e9+5;
	for(int k=0;k<n;k++){
		for(int i=0;i<=k;i++){
			for(int j = 0;j<i;j++){
				ans = min(ans,dis[i][j]+side[j][k]+side[k][i]);
				ans = min(ans,dis[j][i]+side[i][k]+side[k][j]);
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++) 
				dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
		}
	}
	if(ans>=1e9){
		cout<<-1<<"\n";
	}else{
		cout<<ans<<"\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	while(cin>>n && n){
		solve();		
	}

	return 0;
}
