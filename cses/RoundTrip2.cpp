#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N = 1e5+5;
vector<int> side[N];
bool instk[N];
int p[N];
//bool havep[N];
void backtrack(int pa,int v){
	stack<int> ans;		
	while(v!=pa){
		ans.push(v);
		v = p[v];
	}
	cout<<ans.size()+2<<"\n";
	cout<<pa<<" ";
	while(ans.size()){
		cout<<ans.top()<<" ";
		ans.pop();
	}
	cout<<pa<<"\n";
	exit(0);
}
void dfs(int v){
	instk[v]=1;		
	for(auto i : side[v]){
		if(!p[i]){
			p[i] = v;
			dfs(i);
		}else{
			if(instk[i]){
				backtrack(i,v);
			}
		}
	}
	instk[v]=0;
	
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	while(m--){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
	}
	for(int i=1;i<=n;i++){
		if(!p[i]) dfs(i);
	}
	cout<<"IMPOSSIBLE\n";
	return 0;
}
