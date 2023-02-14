#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

void solve(){
	int n;cin>>n;
	int a  = 0;
	int arr[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
		a^=arr[i];
	}
	if(a==0){
		cout<<"DRAW\n";
		return;
	}
	int p = __lg(a);
	int x=0;int y = 0;
	for(int i=0;i<n;i++){
		if((arr[i]>>p)&1) x++;
		else y++;
	}
	if(x%4==3 && y%2==0){
		cout<<"LOSE\n";
	}else{
		cout<<"WIN\n";
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
