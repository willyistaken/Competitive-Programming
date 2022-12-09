#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


vector<int> side[100005];
int p[100005];
int d[100005];
bool dfs(int cur){
	for(auto i : side[cur]){
		if(!d[i]){
			p[i] = cur;
			d[i]= d[cur]+1;
			if(dfs(i)) return 1;
		}else if(i!=p[cur]){
			int a = i;	
			int b = cur;
			if(d[a]>d[b]) swap(a,b);
			int end = a;
			queue<int> ast;
			stack<int> bst;
			while(d[b]>d[a]){
				bst.push(b);
				b = p[b];
			}
			while(a!=b){
				ast.push(a);
				bst.push(b);
				a = p[a];
				b = p[b];
			}
			ast.push(a);
			cout<<ast.size()+bst.size()+1<<"\n";
			while(ast.size()){
				cout<<ast.front()<<" ";
				ast.pop();
			}
			while(bst.size()){
				cout<<bst.top()<<" ";
				bst.pop();
			}
			cout<<end<<"\n";
			return 1;
		}
	}
	return 0;
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
		if(!d[i]){
			d[i]=1;
			p[i]=i;
			if(dfs(i)) return 0;
		}
	}
	cout<<"IMPOSSIBLE\n";
	return 0;
}
