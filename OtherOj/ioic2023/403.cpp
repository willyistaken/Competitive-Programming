#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N = 5e5+5;
vector<int> side[N];

int maxd[N];
bool vis[N];
void dfs(int cur){
	vis[cur]=1;	
	for(auto i : side[cur]){
		if(!vis[i]) dfs(i);
	}
											
}



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
		

	return 0;
}
