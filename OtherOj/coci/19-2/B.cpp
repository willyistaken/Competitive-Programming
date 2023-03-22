#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


vector<pair<int,int>> side[4];
	
int from[9] = {0,3,3,2,2,0,0,3,2};
int to[9] =   {0,2,3,2,3,2,3,1,1};
int deg[4];

stack<int> ans;

void dfs(int cur){
	while(side[cur].size()){
		int k = side[cur].back().first;
		int p = side[cur].back().second;
		side[cur].pop_back();
		dfs(p);
		ans.push(k);
	}
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;	
	for(int i=0;i<n;i++){
		int t,a;cin>>t>>a;
		side[from[t]].push_back({a,to[t]});
		deg[from[t]]--;
		deg[to[t]]++;
	}
	if(deg[0]!=-1 || deg[1]!=1 || deg[2]!=0 || deg[3]!=0){
		cout<<-1<<"\n";
		return 0;
	}
	for(int i=0;i<4;i++) sort(side[i].begin(),side[i].end(),[](pair<int,int> &a,pair<int,int> &b){return a.first>b.first;});
	dfs(0);
	while(ans.size()){
		cout<<ans.top()<<" ";
		ans.pop();
	}
	cout<<"\n";
	return 0;
}
