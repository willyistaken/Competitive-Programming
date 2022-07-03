#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,c;
inline ll hashcor(int x,int y){
	return x*m + y;
}
vector<int> father;

int query(int ind){
	if(father[ind]==ind) return ind;
	father[ind] = query(father[ind]);
	return father[ind];
}
void join(int a,int b){
	father[query(a)] = query(b);
	return ;
}
bool inline inbound(int x,int y){
	return (x>=0 && x<n && y>=0 && y<m);
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>c;
	father.resize(c);
	unordered_map<ll,int> s;
	vector<pair<int,int> > v;
	for(int i=0;i<c;i++){
		int x,y;cin>>x>>y;
		x--;y--;
		v.push_back({x,y});
		s.insert({hashcor(x,y),i});	
		father[i]=i;
	}
	for(int i=0;i<c;i++){
		for(int dx=-2;dx<=2;dx++){
			for(int dy=-2;dy<=2;dy++){
				if(inbound(v[i].first+dx,v[i].second+dy)){
					if(s.count(hashcor(v[i].first+dx,v[i].second+dy))){
						join(i,s[hashcor(v[i].first+dx,v[i].second+dy)]);
					}
				}
			}
		}
	}
	set<int> cons;
	for(int i=0;i<c;i++){
		cons.insert(query(i));
	}
	cout<<cons.size()<<"\n";	



	return 0;
}
