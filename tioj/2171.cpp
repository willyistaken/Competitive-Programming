#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

vector<vector<int> > side;
vector<int> deg;
int cnt = 0;
vector<bool> vis;

void dfs(int cur){
	vis[cur]=1;
	cnt+=deg[cur]&1;
	for(auto i : side[cur]){
		if(!vis[i]) dfs(i);
	}
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n1,n2,s,m,k;cin>>n1>>n2>>s>>m>>k;
	side.resize(n1+n2);
	deg.resize(n1+n2);
	vis.resize(n1+n2,0);
	for(int i=0;i<k;i++){
		int a,b,m;cin>>a>>b>>m;
		a--;
		b--;
		b+=n1;
		side[a].push_back(b);
		side[b].push_back(a);
		deg[a]++;
		deg[b]++;
	}
	int sum = 0;
	for(int i=0;i<n1+n2;i++){
		if(deg[i] && !vis[i]) {
			cnt = 0;
			dfs(i);
			sum+=max(1,(cnt/2));
		}
	}
	cout<<sum<<"\n";
	return 0;
}
