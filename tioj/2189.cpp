#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

/*
	pair dp[i][0](inside);
	pair dp[i][1] (longest);


  */

const int N = 1e5+5;
bool vis[N];
pair<int,int> len[N];
pair<int,int> ans[N];

pair<int,int> Max(pair<int,int> a,int b){
	if(b==a.first || b==a.second) return a;
	if(b>a.first) return {b,a.first};
	if(b>a.second) return {a.first,b};
	return a;
}


vector<pair<int,int> > side[N];
void dfs(int cur){
	vis[cur]=1;	
	for(auto i : side[cur]){
		if(vis[i.first]) continue;
		dfs(i.first);
		ans[cur] = Max(ans[cur],ans[i.first].first);
		ans[cur] = Max(ans[cur],ans[i.first].second);
		ans[cur] = Max(ans[cur],len[i.first].first+len[cur].second+i.second);
		ans[cur] = Max(ans[cur],len[i.first].second+len[cur].first+i.second);
		ans[cur] = Max(ans[cur],len[i.first].first+len[cur].first+i.second);
		len[cur] = Max(len[cur],len[i.first].first+i.second);
		len[cur] = Max(len[cur],len[i.first].second+i.second);
	}
	//cout<<ans[cur].first<<" "<<ans[cur].second<<" "<<cur<<"\n";
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<n;i++){
		int a,b;cin>>a>>b;
		int c;cin>>c;
		side[a].push_back({b,c});
		side[b].push_back({a,c});
	}
	dfs(0);
	cout<<ans[0].second<<"\n";
	return 0;
}
