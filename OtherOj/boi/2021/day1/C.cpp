#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
int l;
int n,m;
int mp(int c,int x){
	x%=l;
	return (n*x+c);
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	vector<vector<int>> side(n);
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		a--;
		b--;
		side[a].push_back(b);
		side[b].push_back(a);
	}
	int k;cin>>k;
	if(k>1) return 0;
	cin>>l;
	vector<int> node(l);
	for(int i=0;i<l;i++) cin>>node[i];
	for(int i=0;i<l;i++) node[i]--;

	vector<bool> vis(n*l);
	for(int i=0;i<l;i++){
		vis[mp(node[i],i)]=1;
	}
	queue<pair<int,int> > q;	
	q.push({mp(0,0),0});
	vis[0]=1;
	while(q.size())	{
		auto cur =q.front();
		q.pop();
		if((cur.first%n)==(n-1)){
			cout<<cur.second<<"\n";
			return 0;
		}
		int u = cur.first%n;
		int t = cur.first/n;
		if(!vis[mp(u,t+1)]){
			vis[mp(u,t+1)]=1;
			q.push({mp(u,t+1),cur.second+1});
		}
		for(auto i : side[u]){
			if(node[t]==i && node[(t+1)%l]==u) continue;
			if(!vis[mp(i,t+1)]){
				vis[mp(i,t+1)]=1;
				q.push({mp(i,t+1),cur.second+1});
			}
		}
	}
	cout<<"impossible\n";

	return 0;
}
