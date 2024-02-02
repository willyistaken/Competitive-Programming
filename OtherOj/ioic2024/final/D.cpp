#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

void solve(){
	ll x1,y1,x2,y2,x3,y3;cin>>x1>>y1>>x2>>y2>>x3>>y3;
	if((x3-x2)*(y2-y1)==(y3-y2)*(x2-x1)){
		if((x1==x2 && y1==y2) || (x2==x3 && y2==y3) || (x1==x3 && y1==y3)){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}else{
		cout<<"YES\n";
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
