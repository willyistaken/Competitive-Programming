#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[4]={1,0,0,-1};
int dy[4]={0,1,-1,0};
int arr[1002][1002];
int n,m;
void dfs(int x,int y){
		arr[x][y]=0;
		for(int i=0;i<4;i++){
			if(arr[x+dx[i]][y+dy[i]]) dfs(x+dx[i],y+dy[i]);
		}
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	memset(arr,0,sizeof(arr));
	for(int i=1;i<=n;i++){
		string s;cin>>s;
		for(int j=1;j<=m;j++){
			if(s[j-1]=='.')	 arr[i][j]=1;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(arr[i][j]){
				ans++;
				dfs(i,j);
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
