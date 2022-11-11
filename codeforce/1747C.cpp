#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

void solve(){
	int n;cin>>n;
	int b;cin>>b;
	int minn = b;
	for(int i=0;i<n-1;i++){
		int a;cin>>a;
		minn = min(a,minn);
	}
	if(minn==b) cout<<"Bob\n";
	else cout<<"Alice\n";
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--) solve();

	return 0;
}
