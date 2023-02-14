#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

vector<ll> get(ll f){
	vector<ll> r;
	for(ll i =1;i*i<=f;i++){
		if(f%i!=0) continue;
		ll g = f/i;
		if(g<i) break;
		r.push_back(i);
		if(i!=g) r.push_back(g);
	}
	return r;
}

void solve(){
	ll n,m1,m2;cin>>n>>m1>>m2;
	vector<ll> f1 = get(m1);
	vector<ll> f2 = get(m2);
	vector<ll> c;
	for(auto i : f1){
		for(auto j : f2){
			c.push_back(i*j);
		}
	}
	sort(c.begin(),c.end());
	c.resize(unique(c.begin(),c.end())-c.begin());
	vector<int> intable;
	int i = 0;
	int cnt = 0;
	ll ans = 0;
	for(;i<c.size() && c[i]<=n;i++){
		intable.push_back(c[i]);
		cnt++;
	}
	ans = intable.size()&1;
	for(;i<c.size() && c[i]<=n*n;i++){
		for(int j =intable.size()-1;j>=0;j--){
			if(c[i]%intable[j]==0 && c[i]/intable[j]<=n){
				cnt++;
				ans^=c[i]/intable[j];
				break;
			}
		}
	}
	cout<<cnt<<" "<<ans<<"\n";
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
