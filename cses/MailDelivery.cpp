#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N = 1e5+5;
set<int> side[N];
stack<int> stk;
void dfs(int v){
	while(side[v].size()){
		int a = *side[v].begin();
		side[a].erase(v);
		side[v].erase(a);
		dfs(a);
	}
	stk.push(v);
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;	
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		side[a].insert(b);
		side[b].insert(a);
	}
	for(int i=1;i<=n;i++){
		if(side[i].size()%2){
			cout<<"IMPOSSIBLE\n";
			return 0;
		}
	}
	dfs(1);
	if(stk.size()!=m+1){
		cout<<"IMPOSSIBLE\n";
		return 0;
	}
	while(stk.size()){
		cout<<stk.top()<<" ";
		stk.pop();	
	}
	cout<<"\n";
	return 0;
}
