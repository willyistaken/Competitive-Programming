#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N = 1e5+5;
stack<int> side[N];
stack<int> stk;
void dfs(int v){
	while(side[v].size()){
		int a = side[v].top();
		side[v].pop();
		dfs(a);
	}
	stk.push(v);
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	int inde[n+1] = {0};
	int outde[n+1] = {0};
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		side[a].push(b);
		outde[a]++;
		inde[b]++;
	}
	if(!(outde[1]-inde[1]==1) || !(inde[n]-outde[n]==1)){
		cout<<"IMPOSSIBLE\n";
		return 0;
	}
	for(int i=2;i<n;i++){
		if(inde[i]!=outde[i]){
			cout<<"IMPOSSIBLE\n";
			return 0;
		}
	}
	dfs(1);
	if(stk.size()!=m+1){
		cout<<"IMPOSSIBLE\n";
		return 0;
	}
	vector<int> ans;	
	while(stk.size()){
		ans.push_back(stk.top());
		stk.pop();
	}
	for(auto i : ans) cout<<i<<" ";
	cout<<"\n";
	return 0;
}
