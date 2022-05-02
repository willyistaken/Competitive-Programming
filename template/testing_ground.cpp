#include <iostream>
using namespace std;
int n, m, c, ans,
	dx[8] = {1, 0, -1, 1, -1, 1, 0, -1},
	dy[8] = {1, 1, 1, 0, 0, -1, -1, -1};
bool g[1002][1002];
inline bool in(int i, int j){
	return i >= 0 and j >= 0 and i < n and j < m;
}
void dfs(int i, int j){
	g[i][j] = 0;
	for(int k = 0; k < 8; ++k)
		if(g[i+dx[k]][j+dy[k]])
			dfs(i+dx[k], j+dy[k]);
}

int main(){
	while(true){
		cin>>n;cin>>m;
		if(n==0) break;
		 ans = 0;
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= m; ++j){
				do{
					c = getchar();
				}while(c < '0');
				g[i][j] = (c=='1');
			}
		}
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= m; ++j){
				if(g[i][j]) ++ans, dfs(i, j);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}