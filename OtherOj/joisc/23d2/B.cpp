#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
#define pii pair<int,int>
#define ff first
#define ss second
const int M = (1<<20)+5;
const int N = 300005;
pair<int,int> dis[M][2];
bool vote[N][20];
int ans[M];
int rs = 0;	
int n,m;
int care[20];
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<(1<<m);i++){
		for(int b=0;b<2;b++) dis[i][b] = {1e9,-1};
	}
	queue<pii > q;
	for(int i=0;i<n;i++){
		int s=0;
		for(int j=0;j<m;j++){
			cin>>vote[i][j];
			if(vote[i][j]) s+=(1<<j);
		}
		if(dis[s][0].ff!=1e9){
			dis[s][1] = {0,i};
			q.push({s,1});
		}else{
			dis[s][0] = {0,i};
			q.push({s,0});
		}
	}
	int base=0;
	for(int i=0;i<m;i++){
		int cnt = 0;	
		for(int j=0;j<n;j++) if(vote[j][i]) cnt++;
		care[i]=0;
		if(cnt==(n/2)){
			care[i]=1;
		}else if(cnt==(n/2)+1){	
			care[i]=2;
		}else if(cnt>=(n/2)+2) base++;
	}
	while(q.size()){
		pii cur = q.front();
		q.pop();
		//for(int j=0;j<m;j++) cout<<((cur.ff>>j)&1);
		//cout<<": "<<dis[cur.ff][cur.ss].ff<<" "<<dis[cur.ff][cur.ss].ss<<"\n";
		for(int j=0;j<m;j++){
			int c= cur.ff^(1<<j);
			if(dis[c][0].ff>dis[cur.ff][cur.ss].ff+1){
				dis[c][0] = {dis[cur.ff][cur.ss].ff+1, dis[cur.ff][cur.ss].ss};
				q.push({c,0});
			}else if(dis[c][1].ff>dis[cur.ff][cur.ss].ff+1 && dis[c][0].ss!=dis[cur.ff][cur.ss].ss){
				dis[c][1] = {dis[cur.ff][cur.ss].ff+1,dis[cur.ff][cur.ss].ss};
				q.push({c,1});
			}
		}
		//for(int i=0;i<(1<<m);i++) cout<<dis[i][0].ff<<","<<dis[i][0].ss<<" "<<dis[i][1].ff<<","<<dis[i][1].ss<<"|\n"[(i%4==3)];
		//cout<<"\n\n\n";
	}

			

	for(int j=0;j<m;j++){
		for(int i=0;i<(1<<m);i++){
			if((i>>j)&1){
				int c = i^(1<<j);
				if(dis[i][1].ff<dis[c][0].ff) continue;					
				if(dis[i][0].ff>dis[c][1].ff){
					dis[i][0] = dis[c][0];
					dis[i][1] = dis[c][1];
					continue;
				}	
				if(dis[i][0].ss!=dis[c][0].ss){
					if(dis[i][0].ff<dis[c][0].ff) dis[i][1] = dis[c][0];
					else{
						dis[i][1] = dis[i][0];
						dis[i][0] = dis[c][0];
					}
				}else{
					dis[i][0] = min(dis[i][0],dis[c][0]);
					dis[i][1] = min(dis[i][1],dis[c][1]);
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		int re = base;
		int s=0;
		int posi=0;
		for(int j=0;j<m;j++){
			if(vote[i][j]!=care[j]-1) s+=(1<<j);
			else posi++;
			if(care[j]==2 && vote[i][j]==0) re++;
		}
		if(dis[s][0].ss==i) posi-=dis[s][1].ff;
		else posi-=dis[s][0].ff;
		cout<<re+posi<<"\n";
	}
	return 0;
}
