#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
int n,k;
vector<int> arr;

bool check(ll g){
	for(int i=0;i<n;i++){
		ll need = 0;
		ll hastobe = g;
		for(int j=i;j<n+1;j++){
			if(arr[j]>=hastobe)	break;
			need+=hastobe-arr[j];
			hastobe--;
		}
		if(need<=k) return 1;
	}
	return 0;
}



void solve(){
	cin>>n>>k;
	arr.resize(n);
	int ans = 0;
	for(int i=0;i<n;i++){cin>>arr[i]; ans = max(ans,arr[i]);}
	arr.push_back(-1e8);
	ll l = ans;ll r = 1e10;
	while(r-l>1){
		ll mid = (l+r)/2;
		if(check(mid)) l = mid;
		else r = mid;
	}
	cout<<l<<"\n";
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
