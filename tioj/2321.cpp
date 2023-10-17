#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 2e5+5;
pair<int,int> dep[N];
int t;
vector<int> side[N];
int p[N][20];
void dfs(int cur){
	dep[cur].first=++t;
	for(auto e : side[cur]){
		if(!dep[e].first){
			p[e][0]=cur;
			dfs(e);
		}
	}
	dep[cur].second=++t;
}
bool vis[N];
void fdfs(int a,int cur){
	if(cur==a) return;
	vis[cur]=1;
	for(auto e : side[cur]){
		if(!vis[e]) fdfs(a,e);
	}
}
bool isanc(int a,int b){
	return (dep[a].first<dep[b].first && dep[a].second>dep[b].second);
}
int plca(int a,int b){
	for(int g=19;g>=0;g--){
		if(!isanc(p[b][g],a)) b = p[b][g];
	}
	return b;
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	for(int i=0;i<n-1;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
	}
	p[1][0]=1;
	dfs(1)	;
	for(int g=1;g<20;g++){
		for(int i=1;i<=n;i++){
			p[i][g] = p[p[i][g-1]][g-1];
		}
	}
	int q;cin>>q;
	while(q--){
		int a,b;cin>>a>>b;
		if(isanc(a,b)){
			int c = plca(a,b);
			fdfs(a,c);
		}else{
			fdfs(a,p[a][0]);
		}
	}
	int ans= 0 ;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			ans++;
		}
	}
	cout<<ans<<"\n";
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			cout<<i<<" ";
		}
	}
	cout<<"\n";
	return 0;
}
