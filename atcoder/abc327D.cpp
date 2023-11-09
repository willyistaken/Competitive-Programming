#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 2e5+5;
vector<int> side[N];
int vis[N];
int n,m;

bool dfs(int cur){
	bool c = 0;
	for(auto i : side[cur]){
		if(!vis[i]){
			vis[i] = 3-vis[cur];
			c|=dfs(i);
		}else{
			if(vis[i]==vis[cur]) {return 1;}
		}
	}
	return c;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;	
	vector<int> a(m);
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		int b;cin>>b;
		side[a[i]].push_back(b);
		side[b].push_back(a[i]);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(dfs(i)){
				cout<<"No\n";
				return 0;
			}
		}
	}
	cout<<"Yes\n";
	return 0;
}
