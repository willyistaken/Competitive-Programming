#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
#define int ll
const int N = 2000000;
ll dis[505][505];
ll ans[N];
int H,W;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
vector<pair<int,int> > loc;
int a,b,c;
bool inbound2(int x,int y){
	return (x>=0 && x<=H && y>=0 && y<=W);
}

int mp(int x,int y,int l){
	return ((W+1)*(x)+y)+(((H+1)*(W+1))*l);
}
pair<pair<int,int> ,int > rb(int ind){
	int y = ind%(W+1);
	int x = (ind%((W+1)*(H+1))-y)/(W+1);
	int l = ind-(W+1)*x-y;
	l/= (H+1)*(W+1);
	return make_pair(make_pair(x,y),l);
}
void get_dis(){
	for(int i=0;i<=H;i++){
		for(int j=0;j<=W;j++) dis[i][j]=1e15;
	}
	queue<pair<int,int> > q;
	for(auto i :loc){
		dis[i.first][i.second]=0;
		q.push(i);
	}
	while(q.size()){
		pair<int,int> cur = q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int x = cur.first+dx[i];
			int y = cur.second+dy[i];
			if(!inbound2(x,y)) continue;
			if(dis[x][y]<1e15) continue;
			dis[x][y] = dis[cur.first][cur.second]+c;
			q.push({x,y});
		}
	}
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>H>>W;		
	cin>>a>>b>>c;
	int n;cin>>n;
	for(int i=0;i<n;i++){
		pair<int,int> f;
		cin>>f.first>>f.second;
		loc.push_back(f);
	}
	get_dis();
	/*for(int i=0;i<=H;i++){
		for(int j=0;j<=W;j++){
			cout<<setw(5)<<dis[i][j]<<" ";
		}
		cout<<"\n";
	}*/
	for(int i=0;i<N;i++) ans[i] = 1e18;
	ans[mp(loc[0].first,loc[0].second,0)]=0;
	priority_queue<pair<ll,int> ,vector<pair<ll,int> >,greater<pair<ll,int> > > pq;
	pq.push({0,mp(loc[0].first,loc[0].second,0)});
	while(pq.size()){
		pair<ll,int> cur=  pq.top()	;
		pq.pop();
		if(cur.first!=ans[cur.second]) continue;
		pair<pair<int,int>,int> cor = rb(cur.second);
		if(cor.second==0){
			for(int k=0;k<4;k++){
				if(ans[mp(cor.first.first,cor.first.second,k+1)]>ans[cur.second]+dis[cor.first.first][cor.first.second]+b){
					ans[mp(cor.first.first,cor.first.second,k+1)] =ans[cur.second]+dis[cor.first.first][cor.first.second]+b; 
					pq.push({ans[mp(cor.first.first,cor.first.second,k+1)],mp(cor.first.first,cor.first.second,k+1)});
				}
				int x= cor.first.first+dx[k];
				int y = cor.first.second+dy[k];
				if(!inbound2(x,y)) continue;
				if(ans[mp(x,y,0)]>ans[cur.second]+c){
					ans[mp(x,y,0)] = ans[cur.second]+c;
					pq.push({ans[mp(x,y,0)],mp(x,y,0)});
				}
				
			}
		}else{
			int gg = cor.second;	
			gg--;
			int x=  cor.first.first+dx[gg];
			int y=  cor.first.second+dy[gg];
			if(inbound2(x,y)){
				if(ans[mp(x,y,cor.second)]>ans[cur.second]+a){
					ans[mp(x,y,cor.second)]=ans[cur.second]+a;
					pq.push({ans[mp(x,y,cor.second)],mp(x,y,cor.second)});
				}
			}
			if(ans[mp(cor.first.first,cor.first.second,0)]>ans[cur.second]){
				ans[mp(cor.first.first,cor.first.second,0)] = ans[cur.second];
				pq.push({ans[mp(cor.first.first,cor.first.second,0)],mp(cor.first.first,cor.first.second,0)});
			}
		}
	}
	cout<<ans[mp(loc[n-1].first,loc[n-1].second,0)]<<"\n";
	return 0;
}
