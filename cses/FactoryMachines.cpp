#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

vector<int> mac;
int t;

bool check(ll m){
	ll cnt = 0;
	for(auto i : mac){
		cnt+=m/i;
		if(cnt>=t) return 1;
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;	
	cin>>t;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		mac.push_back(a);
	}
	ll l = -1;ll r = 1e18+5;
	while(r-l>1){
		ll mid = (l)+((r-l)/2);
		if(check(mid)) r = mid;
		else l = mid;
	}
	cout<<r<<"\n";
	return 0;
}
