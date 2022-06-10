#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
inline bool inbound(int x,int y){
	return (x>=0 && x<n && y>=0 && y<m);
}
int dx[4] ={0,0,1,-1};
int dy[4]={1,-1,0,0};
int dfs(int type,int x,int y,vector<vector<int> > &arr){
	arr[x][y]=-1;
	int sum=0;
	for(int i=0;i<4;i++){
		if(inbound(x+dx[i],y+dy[i])){
			if(arr[x+dx[i]][y+dy[i]]==type ){
				arr[x+dx[i]][y+dy[i]]=-1;
				sum += dfs(type,x+dx[i],y+dy[i],arr);
			}
		}
	} 
	return sum+1;
} 
int main(){ 
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	cin>>n>>m; 
	vector<vector<int> >  arr(n,vector<int>(m,-1)); 
	for(int i=0;i<n;i++){ 
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	int maxn=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]>=0){
				int now = dfs(arr[i][j],i,j,arr);
				maxn = max(maxn,now);	
			}
		}
	}
	cout<<maxn<<endl;
	return 0;
}
