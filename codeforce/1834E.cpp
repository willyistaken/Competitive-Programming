#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

void solve(){
	int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	ll limit = 1e8;
	vector<ll> opt;
	vector<ll> itoright;
	for(int i=0;i<n;i++){
		vector<ll> thisone;	
		thisone.push_back(arr[i]);
		for(auto x : itoright){
			ll k = (1LL*arr[i]*x)/(__gcd((ll)arr[i],x));
			if(k<limit){
				thisone.push_back(k);
			}
		}
		sort(thisone.begin(),thisone.end());
		thisone.resize(unique(thisone.begin(),thisone.end())-thisone.begin());
		itoright.clear();
		for(auto v : thisone){
			itoright.push_back(v);
			opt.push_back(v);
		}
	}
	sort(opt.begin(),opt.end());
	unique(opt.begin(),opt.end());
	int ans = 1;
	for(auto i : opt){
		if(ans==i) ans++;
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
