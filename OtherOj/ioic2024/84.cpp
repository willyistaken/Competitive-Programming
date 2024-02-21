#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


int square[1001][1001];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int x = 0;
	int y = (n/2);
	for(int i=1;i<=n*n;i++){
		square[x][y]=i;
		x--;y++;
		x%=n;
		y%=n;
		if(x<0) x+=n;
		if(y<0) y+=n;
		if(square[x][y]){
			x+=2;y--;
			y%=n;
			x%=n;
			if(y<0) y+=n;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<square[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
