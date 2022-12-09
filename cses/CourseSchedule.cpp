#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N  = 1e5+5;
vector<int> side[N];
bool vis[N];
int ord[N];
int t;
void dfs(int v){
	vis[v]=1;	
	for(auto i : side[v]){
		if(!vis[i]) dfs(i);
	}
	ord[v]=++t;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	while(m--){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
	}
	for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);
	int arr[n];			
	for(int i=0;i<n;i++) arr[i] = i+1;
	sort(arr,arr+n,[&](int a,int b){return ord[a]>ord[b];});
	for(int i=0;i<n;i++){
		for(auto j : side[arr[i]]){
			if(ord[j]>ord[arr[i]] ){
				cout<<"IMPOSSIBLE\n";
				return 0;
			}
		}
	}
	for(auto i : arr) cout<<i<<" ";
	cout<<"\n";
	return 0;
}
