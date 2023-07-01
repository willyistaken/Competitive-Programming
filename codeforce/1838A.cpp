#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


void solve(){
	int n;cin>>n;
	int maxn = INT_MIN;
	int minn = INT_MAX;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		minn = min(minn,a);
		maxn = max(maxn,a);
	}
	if(minn<0){
		cout<<minn<<"\n";
	}else{
		cout<<maxn<<"\n";
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
