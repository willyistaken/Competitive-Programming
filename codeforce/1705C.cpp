#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


string s;int n,c,q;

vector<pair<ll,ll> > cp;

char get(ll k){
	if(k <= n) return s[k-1];
	ll sumlength=0;
	ll which=0;
	for(int i=0;i<=c;i++){
		sumlength += cp[i].second;	
		if(sumlength>=k){
			which=i;
			sumlength-=cp[i].second;
			break;
		}
	}
	return get(cp[which].first+k-(sumlength)-1);
}



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		cp.clear();
		cin>>n>>c>>q;
		cp.push_back({1,n});
		cin>>s;
		for(int i=0;i<c;i++){
			ll l,r;cin>>l>>r;
			cp.push_back({l,r-l+1});
		}
		while(q--){
			ll k;cin>>k;
			cout<<get(k)<<"\n";
		}

	}
	return 0;
}
