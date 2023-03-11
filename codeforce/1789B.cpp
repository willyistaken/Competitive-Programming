#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

void solve(){
	int n;cin>>n;
	string s;cin>>s;
	vector<bool> arr(n/2);
	for(int i=0;i<n/2;i++){
		if(s[i]==s[n-i-1]) arr[i] = 0;
		else arr[i]=1;
	}
	int haso = 0;
	for(int i=0;i<n/2;i++){
		if(arr[i]){
			if(haso==2){
				cout<<"No\n";
				return ;
			}else{
				haso = 1;
			}
		}else{
			if(haso==1) haso=2;
		}
		
	}
	cout<<"Yes\n";
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
