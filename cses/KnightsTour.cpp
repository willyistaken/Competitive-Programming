#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


int dx[8] = {1,1,2,2,-1,-1,-2,-2};
int dy[8] = {2,-2,1,-1,2,-2,1,-1};
int cnt[8][8];
bool inb(int x,int y){
	if(x<0 || x>=8 || y<0 || y>=8) return 0;
	else return 1;
}
int vis[8][8];
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int curx,cury;cin>>curx>>cury;
	curx--;cury--;	
	swap(curx,cury);
	int a =curx;int b =cury;
	int ord[8];
	for(int i=0;i<8;i++) ord[i]=i;
	while(true){
	curx = a;cury = b;

	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			cnt[i][j]=0;
			for(int k=0;k<8;k++){
				if(inb(i+dx[k],j+dy[k])) cnt[i][j]++;
			}
		}
	}
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=64;i++){
		vis[curx][cury]	 = i;
		cnt[curx][cury]=1e9;
		int minn = 1e9;
		int mink = -1;
		srand(time(0));
		random_shuffle(ord,ord+8);
		for(int g=0;g<8;g++){
			int k = ord[g];
			if(inb(curx+dx[k],cury+dy[k])){
				cnt[curx+dx[k]][cury+dy[k]]--;
				if(minn>cnt[curx+dx[k]][cury+dy[k]]){
					minn = cnt[curx+dx[k]][cury+dy[k]];
					mink = g;
				}
			}
		}
		curx+=dx[ord[mink]];
		cury+=dy[ord[mink]];
	}
		bool zo = 0;	
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				if(vis[i][j]==0){
					zo = 1;
					break;
				}
			}
		}
		if(!zo){
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				cout<<vis[i][j]<<" ";
			}
			cout<<"\n";
		}
		return 0;
		}
	}
}
// heuristic and randomnize algorithm
