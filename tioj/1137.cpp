#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
vector<int> height(10005);
vector<vector<int> > side;
vector<int> low(10005);
set<int> ans;
int id;
void dfs(int r,int from){
	height[r]=low[r]=++id;	
	int subtree=0;
	for(auto i : side[r]){
		if(i!=from){
			if(height[i]) {
				low[r] = min(low[r],height[i]);		
			}else{
				subtree++;
				dfs(i,r);
				low[r] = min(low[r],low[i]);
				if(low[i]>=height[r]  && r!=1){
					ans.insert(r);
				}
			}
		}
	}
	if(r==1 && subtree>1) ans.insert(r);
	return ;
}



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n>>m;	
		id=0;
		ans.clear();
		side.clear();
		side.resize(n+1);
		fill(low.begin(),low.end(),0);	
		fill(height.begin(),height.end(),0);	
		for(int i=0;i<m;i++){
			int a,b;cin>>a>>b;
			if(a==b) continue;
			side[a].push_back(b);
			side[b].push_back(a);
		}
		dfs(1,0);	
		if(ans.size()){
			cout<<ans.size()<<"\n";
			for(auto i : ans){
				cout<<i<<" ";
			}
			cout<<"\n";
		}else{
			cout<<"0\n0\n";
		}











	}
	return 0;
}
