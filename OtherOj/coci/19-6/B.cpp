#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N = 100000+5;
int dis[N];
vector<int> side[N];
int n,m,q,k;
int get(int g){
	g--;
	if(g==0) return 0;
	ll l = 0;ll r = 100005;
	while(r-l>1){
		ll mid=(l+r)/2;
		if(k*((mid*mid+mid)/2)>=g) r = mid;
		else l = mid;
	}
	return r;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>q>>k;
	queue<int> bfs;
	for(int i=0;i<q;i++){
		int a;cin>>a;
		dis[a]=1;
		bfs.push(a);
	}
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
	}
	while(bfs.size()){
		int cur = bfs.front();
		bfs.pop();
		for(auto i : side[cur]){
			if(!dis[i]){
				dis[i] = dis[cur]+1;
				bfs.push(i);
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<get(dis[i])<<" ";
	}
	cout<<"\n";
	return 0;
}
