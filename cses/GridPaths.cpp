#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
string s;
ll ans;
int p[48];
bool arr[9][9];
int dx[5] = {0,0,0,-1,1};
int dy[5] = {0,-1,1,0,0};
void dfs(int t,int x,int y){
	if((arr[x][y-1] && arr[x][y+1]) &&(!arr[x-1][y] && !arr[x+1][y])) return ;
	if((!arr[x][y-1] && !arr[x][y+1]) &&(arr[x-1][y] && arr[x+1][y])) return ;
	if(x==1 && y==7){
		if(t==48) ans++;
		else return;
	}
	if(t==48) return ;
	arr[x][y] = 1;
	if(p[t]){
		if(!arr[x+dx[p[t]]][y+dy[p[t]]]) dfs(t+1,x+dx[p[t]],y+dy[p[t]]);
	}else{
		for(int i=1;i<=4;i++){
			if(!arr[x+dx[i]][y+dy[i]]) dfs(t+1,x+dx[i],y+dy[i]);
		}
	}
	arr[x][y] = 0;
	return ;	
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>s;
	for(int i=0;i<48;i++){
		if(s[i]=='?') p[i] = 0;
		if(s[i]=='U') p[i]=1;
		if(s[i]=='D') p[i]=2;
		if(s[i]=='L') p[i]=3;
		if(s[i]=='R') p[i]=4;
	}
	for(int i=0;i<9;i++){
		arr[0][i] = 1;
		arr[8][i] = 1;
		arr[i][0] = 1;
		arr[i][8] = 1;
	}
	dfs(0,1,1);
	cout<<ans<<"\n";
	return 0;
}
