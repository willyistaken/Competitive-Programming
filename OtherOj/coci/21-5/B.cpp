#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


bool arr[2005][2005];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int n,m;
bool inbound(int x,int y){
	return (x>=0 && y>=0);
}

int xpymax,xpymin,xmymax,xmymin;
int cnt = 0;
void dfs(int x,int y){
	arr[x][y]=1;
	cnt++;
	xpymax = max(xpymax,x+y);
	xpymin = min(xpymin,x+y);
	xmymax = max(xmymax,x-y);
	xmymin = min(xmymin,x-y);
	for(int i=0;i<4;i++){
		if(inbound(x+dx[i] , y+dy[i])){
			if(arr[x+dx[i]][y+dy[i]]==0){
				dfs(x+dx[i],y+dy[i]);
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;	
	for(int i=0;i<2005;i++){
		arr[i][m+4]=1;
		arr[n+4][i]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char a;cin>>a;
			if(a=='#') arr[i][j]=1;
		}
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!arr[i][j]) {
				xpymax = INT_MIN;
				xpymin = INT_MAX;
				xmymax = INT_MIN;
				xmymin = INT_MAX;
				cnt = 0;
				dfs(i,j);
				//cout<<i<<" "<<j<<"\n";
				//cout<<xpymax<<" "<<xpymin<<" "<<xmymax<<' '<<xmymin<<" "<<cnt<<"\n";
				if(xpymax-xpymin!=xmymax-xmymin || (xpymax-xpymin)%2) continue;
				int l = (xpymax-xpymin)/2+1;
				int area = (2*l*l)-(2*l)+1;
				//cout<<area<<"\n";
				if(cnt==area){
					ans++;
				}
	
						
			}
		}
	}
	cout<<ans<<"\n";
		
	return 0;
}
