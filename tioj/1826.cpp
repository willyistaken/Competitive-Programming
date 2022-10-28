#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


const char dir[4] = {'D','R','U','L'};
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int arr[5][5];
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int sx= 0,sy = 0;
	for(int i=1;i<=3;i++){
		for(int j = 1;j<=3;j++){
			cin>>arr[i][j];
			if(arr[i][j]==1){
				sx = i;
				sy = j;
			}
		}
	}
	bool flag= 1;
	cout<<"*";
	while(flag){
		flag = 0;
		for(int k = 0;k<4;k++){
			if(arr[sx+dx[k]][sy+dy[k]]==arr[sx][sy]+1){
				cout<<dir[k];
				flag = 1;
				sx+=dx[k];
				sy+=dy[k];
				break;
			}
		}
	}
	cout<<"\n";
	return 0;
}
