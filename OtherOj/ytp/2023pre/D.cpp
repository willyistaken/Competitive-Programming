#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
ll issquare(ll a){
	ll l = 0;
	ll r = 1e9+5;
	while(r-l>1){
		ll mid = (l+r)/2;
		if(mid*mid<=a) l = mid;
		else r = mid;
	}
	if(l*l==a) return l;
	else return -1;
}
void solve(){
	int n;cin>>n;
	set<pair<ll,ll> > rq;
	set<pair<pair<ll,ll>,ll> > ri;
	set<pair<pair<ll,ll>,ll> > C;
	for(int i=0;i<n;i++){
		ll a,b,c;cin>>a>>b>>c;
		if(a==0){
			if(b){
				pair<ll,ll> ans = {-c,b};
				ll d = __gcd(-c,b);
				ans.first/=d;
				ans.second/=d;
				if(ans.second<0){
					ans.first=-ans.first;
					ans.second = -ans.second;
				}
				rq.insert(ans);
			}
			continue;
		}
		if(b*b<4*a*c){
			ll d = __gcd(a,b);
			d = __gcd(d,c);
			a/=d;b/=d;c/=d;
			if(a<0){
				a = -a;
				b =-b;
				c = -c;
			}
			pair<pair<ll,ll>,ll> ans = {{a,b},c};
			C.insert(ans);
		}else{
			ll k = b*b-4*a*c;	
			if(issquare(k)>=0){
				ll t = -b+issquare(k);
				ll bt = 2*a;
				ll d = __gcd(t,bt);
				pair<ll,ll> ans = {t/d,bt/d};
				if(ans.second<0){
					ans.first=-ans.first;
					ans.second = -ans.second;
				}
				rq.insert(ans);
				t = -b-issquare(k);
				d = __gcd(t,bt);
				ans = {t/d,bt/d};
				if(ans.second<0){
					ans.first=-ans.first;
					ans.second = -ans.second;
				}
				rq.insert(ans);
			}else{
			ll d = __gcd(a,b);
			d = __gcd(d,c);
			a/=d;b/=d;c/=d;
			if(a<0){
				a = -a;
				b =-b;
				c = -c;
			}
			pair<pair<ll,ll>,ll> ans = {{a,b},c};
			ri.insert(ans);
			}
		}
	}
	ll ans = rq.size()+2*ri.size()+2*C.size();
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
