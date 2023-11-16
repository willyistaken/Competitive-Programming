#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
//#include<bits/extc++.h>
//__gnu_pbds
 
const int N =1e5+5;
bool in[N];
int dir[N];
ll T[N];
pii pt[N];
priority_queue<pii,vector<pii>,greater<pii> > pq;
int n;
int get(){
	while(pq.size()){
		auto cur = pq.top();
		pq.pop();
		if(cur.first!=T[cur.second]) continue;
		if(in[cur.second]) continue;
		in[cur.second]=1;
//		cout<<cur.second<<" "<<T[cur.second]<<" "<<dir[cur.second]<<"w\n";
		int i = cur.second;
		for(int j=1;j<=n;j++){
			if(in[j]) continue;
			ll t=1e18;
			int d=-1;
			if(dir[i]==1){
				if(pt[i].first>pt[j].first)	continue;
				if(pt[i].second==pt[j].second){
					t = abs((pt[i].first-pt[j].first)/2);
					d = 2;
				}
				if(abs(pt[i].first-pt[j].first)==abs(pt[i].second-pt[j].second)){
					t = abs(pt[i].first-pt[j].first);
					d = (pt[i].second>pt[j].second)?(3):(4);
				}
			}
			if(dir[i]==2){
				if(pt[i].first<pt[j].first)	continue;
				if(pt[i].second==pt[j].second){
					t = abs((pt[i].first-pt[j].first)/2);
					d = 1;
				}
				if(abs(pt[i].first-pt[j].first)==abs(pt[i].second-pt[j].second)){
					t = abs(pt[i].first-pt[j].first);
					d = (pt[i].second>pt[j].second)?(3):(4);
				}
			}
			if(dir[i]==3){
				if(pt[i].second>pt[j].second) continue;
				if(pt[i].first==pt[j].first){
					t = abs((pt[i].second-pt[j].second)/2);
					d = 4;
				}
				if(abs(pt[i].first-pt[j].first)==abs(pt[i].second-pt[j].second)){
					t = abs(pt[i].first-pt[j].first);
					d = (pt[i].first>pt[j].first)?(1):(2);
				}
			}
			if(dir[i]==4){
				if(pt[i].second<pt[j].second) continue;
				if(pt[i].first==pt[j].first){
					t = abs((pt[i].second-pt[j].second)/2);
					d = 3;
				}
				if(abs(pt[i].first-pt[j].first)==abs(pt[i].second-pt[j].second)){
					t = abs(pt[i].first-pt[j].first);
					d = (pt[i].first>pt[j].first)?(1):(2);
				}
			}
			if(t<T[j] && t>=T[i]){
				T[j]=t;
				dir[j]=d;
				pq.push({T[j],j});
			}
		}
	}
	int cnt = 0;
	for(int i=1;i<=n;i++) cnt+=in[i];
	return cnt;
}
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>pt[i].first>>pt[i].second;
	int dx = -pt[1].first;
	int dy = -pt[1].second;
	for(int i=1;i<=n;i++){
		pt[i].first+=dx;
		pt[i].second+=dy;
		pt[i].first*=2;
		pt[i].second*=2;
	}
	int maxn = 0;
	for(int d=1;d<=4;d++){
		for(int i=1;i<=n;i++) {in[i]=0;dir[i]=0;T[i]=1e18;}
		dir[1]=d;
		T[1]=0;
		pq.push({0,1});
		int g = get();
		maxn = max(maxn,g);
		while(pq.size()) pq.pop();
	}
	cout<<maxn<<"\n";
 
	return 0;
}
