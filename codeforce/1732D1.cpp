#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int q;cin>>q;
	map<ll,ll> ans;
	set<ll> has;
	while(q--){
		char t;cin>>t;
		ll a;cin>>a;
		if(t=='+'){
			has.insert(a);
		}
		if(t=='?'){
			if(!ans.count(a)) ans[a]=a;
			while(has.count(ans[a])){
				ans[a]+=a;	
			}
			cout<<ans[a]<<"\n";
		}
	}
	return 0;
}
