#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
int arr[1005][1005];
int sx,sy,ex,ey;
int r,c;	
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
bool vis[1005][1005];
bool dfs(int x,int y,int m){
	//cout<<x<<" "<<y<<"\n";
	if(x<0 || x>=r || y<0 || y>=c ) return 0;
	if(vis[x][y]) return 0;
	if(arr[x][y]>m) return 0;
	if(x==ex && y==ey) return 1;
	vis[x][y] = 1;
	for(int i=0;i<4;i++){
		if(dfs(x+dx[i],y+dy[i],m)) return 1;
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>r>>c;
	for(int i= 0;i<1005;i++){
		for(int j = 0;j<1005;j++) arr[i][j] = INT_MAX;
	}
	int l = -1;int r = 1e9+5;
	cin>>sx>>sy>>ex>>ey;
	arr[sx][sy] = 0;
	arr[ex][ey] = 0;
	int t;cin>>t;
	while(t--){
		int x,y,v;cin>>x>>y>>v;
		arr[x][y] = v;
	}
	
	while(r-l>1){
		int mid = l +((r-l)/2);
		memset(vis,0,sizeof(vis));
		if(dfs(sx,sy,mid)) r = mid;
		else l = mid;
	}
	cout<<r<<"\n";
	
	return 0;
}
