#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

void solve(){
	string arr[8];
	for(int i=0;i<8;i++) cin>>arr[i];
	for(int i=0;i<8;i++){
		bool flag = 0;
		for(int j=0;j<8;j++){
			if(arr[i][j]=='B') flag=1;	
		}
		if(!flag){
			cout<<"R\n";
			return ;
		}
	}
	for(int i=0;i<8;i++){
		bool flag = 0;
		for(int j=0;j<8;j++){
			if(arr[j][i]=='R') flag=1;	
		}
		if(!flag){
			cout<<"B\n";
			return ;
		}
	}
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}
	
	return 0;

}
