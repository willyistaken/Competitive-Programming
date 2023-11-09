#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 2e5+5;
int A[N];
vector<int> side[N];
int vis[N];
int n,m;
bool cover(int i){
	set<pair<int,int> > s;
	s.insert({A[i],i});
	int sz = 0;
	while(s.size()){
		auto cur = *s.begin();
		vis[cur.second]=i;
		if(cur.first>sz){
			return sz==n;
		}
		s.erase(s.begin());
		sz++;
		for(auto e : side[cur.second]){
			if(vis[e]<i){
				s.insert({A[e],e});
			}
		}
	}
	return sz==n;
}

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>A[i];
		side[i].clear();
		vis[i]=0;
	}
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		if(!A[i] && !vis[i]){
			if(cover(i)) {
				cout<<"YES\n";
				return ;
			}
		}
	}
	cout<<"NO\n";
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
