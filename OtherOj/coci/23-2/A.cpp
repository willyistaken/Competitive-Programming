#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

string arr[50];
int n,m;

bool inbound(int x,int y){
	return (x<n && x>=0 && y<m && y>=0);
}
int sz(int x,int y){
	int minn = 1e9;	
	// up
	for(int i=1;i<=50;i++){
		if(!(inbound(x+i,y) && arr[x+i][y]=='|')){
			minn = min(minn,i-1);
			break;
		}
	}
	//down
	for(int i=1;i<=50;i++){
		if(!(inbound(x-i,y) && arr[x-i][y]=='|')){
			minn = min(minn,i-1);
			break;
		}
	}
	//right
	for(int i=1;i<=50;i++){
		if(!(inbound(x,y+i) && arr[x][y+i]=='-')){
			minn = min(minn,i-1);
			break;
		}
	}
	//left
	for(int i=1;i<=50;i++){
		if(!(inbound(x,y-i) && arr[x][y-i]=='-')){
			minn = min(minn,i-1);
			break;
		}
	}
	// downright
	for(int i=1;i<=50;i++){
		if(!(inbound(x+i,y+i) && arr[x+i][y+i]=='\\')){
			minn = min(minn,i-1);
			break;
		}
	}
	// downleft
	for(int i=1;i<=50;i++){
		if(!(inbound(x+i,y-i) && arr[x+i][y-i]=='/')){
			minn = min(minn,i-1);
			break;
		}
	}
	// upright
	for(int i=1;i<=50;i++){
		if(!(inbound(x-i,y+i) && arr[x-i][y+i]=='/')){
			minn = min(minn,i-1);
			break;
		}
	}
	// upleft
	for(int i=1;i<=50;i++){
		if(!(inbound(x-i,y-i) && arr[x-i][y-i]=='\\')){
			minn = min(minn,i-1);
			break;
		}
	}
	if(minn>=50) return 0;
	return minn;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;		
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int maxn = 0;
	for(int i=0;i<n;i++)	{
		for(int j=0;j<m;j++){
			if(arr[i][j]=='+') maxn = max(maxn,sz(i,j));
		}
	}
	cout<<maxn<<"\n";

	return 0;
}
