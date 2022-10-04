#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::
int n,T;

int arr[2005][2005];
const int xdir[4] = {1,0,-1,0};
const int ydir[4] = {0,1,0,-1};

void getarr() {
    int dir=0;
    int nowx=1;
    int nowy=1;
    for(int i=(2*n-1)*(2*n-1)-1; i>0; i--) {
        arr[nowx][nowy] = i;
        if(nowx+xdir[dir]>2*n-1 || nowx+xdir[dir]<1 || nowy+ydir[dir]>2*n-1 || nowy+ydir[dir]<1 || arr[nowx+xdir[dir]][nowy+ydir[dir]]) {
			dir+=1;
			dir%=4;
        }
		nowx+=xdir[dir];
		nowy+=ydir[dir];
    }
}

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>T;
    getarr();
	/*for(int i=1;i<=2*n-1;i++){
		for(int j=1;j<=2*n-1;j++) cout<<arr[i][j]<<" ";
		cout<<"\n";
	}*/
    while(T--) {
		int k;cin>>k;
		int r=0;
		for(int i=0;i<k;i++){
			int x,y;cin>>x>>y;
			r^=arr[x][y];
		}
		
		if(r){
			cout<<"A Win!\n";
		}else{
			cout<<"B Win.\n";
		}
    }

    return 0;
}

