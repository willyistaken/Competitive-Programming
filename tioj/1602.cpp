#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int h[1500][1500];
bool works[1500][1500];
inline bool inbound(int x,int y){return (0<=x && n>x && 0<=y && m>y);}
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
void dfs(int x,int y){
	works[x][y]=1;
	for(int i=0;i<4;i++){
		if(inbound(x+dx[i],y+dy[i])){
			if(h[x+dx[i]][y+dy[i]]>=h[x][y] && !works[x+dx[i]][y+dy[i]]){
				dfs(x+dx[i],y+dy[i]);
			}
		}
	}
	return ;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) cin>>h[i][j];
	}
	int x,y;cin>>x>>y;
	dfs(y,x);
	for(int j=0;j<m;j++){
		for(int i=0;i<n;i++){
			if(works[i][j]) cout<<"("<<j<<","<<i<<")\n";
		}
	}
	//werid input output format

	return 0;
}
