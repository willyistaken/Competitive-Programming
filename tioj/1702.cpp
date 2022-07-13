#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int dx[8]={1,1,1,0,0,-1,-1,-1};
int dy[8]={1,0,-1,1,-1,1,0,-1};

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	while(cin>>n>>m){
	int arr[n+2][m+2];
	memset(arr,0,sizeof(arr));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>arr[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int ans=0;
			if(arr[i][j]){
				cout<<"X"<<" ";
				continue;
			}
			for(int k=0;k<8;k++){
				if(arr[i+dx[k]][j+dy[k]]) ans++;
			}
			cout<<ans<<" ";
		}
		cout<<"\n";
	}
	}

	return 0;
}
