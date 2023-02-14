#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


ll calc(ll a,ll b,ll c,ll d){
	ll k = b-c;
	if(a==0) return 0;
	if(a>k){
		return a+b+c+min(d,a-k);
	}else{
		return 2*a+2*c;		
	}

}

void solve(){
	ll a,b,c,d;cin>>a>>b>>c>>d;
	if(b<c) swap(b,c);
	ll g = calc(a,b,c,d);
	if(g<a+b+c+d) cout<<g+1<<'\n';
	else cout<<g<<"\n";
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
