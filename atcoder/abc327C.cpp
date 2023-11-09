#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


int arr[9][9];
bitset<9> yes;
bool ok(){
	bool y = 1;
	for(int i=0;i<9;i++)  y&=yes[i];
	return y;
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++) cin>>arr[i][j];
	}
	bool check = 1;
	for(int i=0;i<9;i++){
		yes.reset();
		for(int k=0;k<9;k++) yes[arr[i][k]-1]=1;
		if(!ok()) check=0;
	}
	for(int i=0;i<9;i++){
		yes.reset();
		for(int k=0;k<9;k++) yes[arr[k][i]-1]=1;
		if(!ok()) check=0;
	}
	for(int k=0;k<3;k++){
	for(int h=0;h<3;h++){
		yes.reset();
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				yes[arr[3*k+i][3*h+j]-1]=1;		
			}
		}
		if(!ok()) check=0;
	}
	}
	if(check) cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
	return 0;
}
