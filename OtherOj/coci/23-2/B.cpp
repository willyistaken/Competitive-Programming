#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N=105;
bool vis[N][N][N];
int n;
bool inbound(int x,int y,int z){
	return (x>0 && x<=n && y>0 && y<=n && z>0 && z<=n);
}
struct cor{
	int x;
	int y;
	int z;
	int t;
};
int dx[6]={1,0,0,0,0,-1};
int dy[6]={0,1,0,-1,0,0};
int dz[6]={0,0,1,0,-1,0};
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	queue<cor> q;
	cor be;
	cin>>be.x>>be.y>>be.z;
	be.t=0;
	q.push(be);
	int xe,ye,ze;cin>>xe>>ye>>ze;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			string s;cin>>s;
			for(int j=1;j<=n;j++){
				vis[i][j][k] = (s[j-1]=='1');
			}
		}
	}
	vis[be.x][be.y][be.z]=1;
	while(q.size()){
		cor cur = q.front();
		q.pop();
		if(cur.x==xe && cur.y==ye && cur.z==ze){
			cout<<cur.t<<"\n";
			return 0;
		}
		for(int i=0;i<6;i++){
			if(inbound(cur.x+dx[i],cur.y+dy[i],cur.z+dz[i])){
				if(!vis[cur.x+dx[i]][cur.y+dy[i]][cur.z+dz[i]]){
					vis[cur.x+dx[i]][cur.y+dy[i]][cur.z+dz[i]]=1;
					cor ne;
					ne.x = cur.x+dx[i];
					ne.y = cur.y+dy[i];
					ne.z = cur.z+dz[i];
					ne.t = cur.t+1;
					q.push(ne);
				}
			}
		}
	}
	cout<<"-1\n";
	return 0;
}
