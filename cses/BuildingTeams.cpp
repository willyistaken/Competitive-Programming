#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 1e5+5;
vector<int>  side[N];
int  vtype[N];

bool dfs(int v){
	for(auto i : side[v]){
		if(!vtype[i]){
			vtype[i] = 3-vtype[v];
			if(!dfs(i)) return 0;
		}else if(vtype[i]==vtype[v]) return 0;
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;	
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		if(!vtype[i]){
			vtype[i]=1;
			if(!dfs(i)){
				cout<<"IMPOSSIBLE\n";
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++) cout<<vtype[i]<<" \n"[i==n];
	return 0;
}
