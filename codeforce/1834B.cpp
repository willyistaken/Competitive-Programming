#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


void solve(){
	string L,R;cin>>L>>R;
	string pad = "";
	int k = R.size()-L.size();
	for(int i=0;i<k;i++) pad+='0';
	L = pad+L;
	int s = R.size();
	bool taken = 0;
	int ans = 0;
	for(int i=0;i<s;i++){
		if(taken) ans+=9;
		else ans+=abs((R[i]-'0')-(L[i]-'0'));
		if(L[i]!=R[i]){
			taken = 1;	
		}
	}
	cout<<ans<<"\n";
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
