#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

void solve(){
	int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	int whole = arr[0];
	for(int i=1;i<n;i++) whole = whole&arr[i];
	if(whole!=0){
		cout<<1<<"\n";
		return ;
	}else{
		int cnt = -1;
		int k = 0;
		for(int i=0;i<n;i++){
			if(k==0){
				cnt++;
				k = arr[i];
			}else{
				k = k&arr[i];
			}
		}
		if(k==0) cnt++;
		cout<<cnt<<"\n";
		return ;
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
