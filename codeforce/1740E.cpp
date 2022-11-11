#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 1e5+5;
vector<int> side[N];

pair<int,int> dfs(int v){
	if(side[v].size()==0) return {1,1};
	int sum = 0;
	int maxn = 0;
	for(auto i : side[v]){
		pair<int,int> g = dfs(i);
		sum+=g.first;
		maxn = max(maxn,g.second);
	}
	return {max(sum,maxn+1),maxn+1};
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	if(n==2){
		cout<<2<<"\n";
		return 0;
	}
	for(int i = 2;i<=n;i++){
		int a;cin>>a;
		side[a].push_back(i);
	}
	cout<<dfs(1).first<<"\n";
	return 0;
}
