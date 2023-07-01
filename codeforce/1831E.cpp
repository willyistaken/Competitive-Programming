#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int MOD = 998244353;

const int N = 3e5+5;

int	fac[2*N+1];

int inv(int a){
	int p = MOD-2;
	ll r = 1;
	while(p){
		if(p&1) r = (r*a)%MOD;
		a = (1LL*a*a)%MOD;
		p>>=1;
	}
	return r;
}

void solve(){
	int n,k;cin>>n>>k;
	vector<int> bp;
	bp.push_back(0);
	bp.push_back(n);
	for(int i=0;i<k;i++){
		int l,r;cin>>l>>r;
		bp.push_back(l-1);
		bp.push_back(r);
	}
	sort(bp.begin(),bp.end());
	bp.resize(unique(bp.begin(),bp.end())-bp.begin());
	int g = bp.size();
	for(auto i : bp) cout<<i<<" ";
	cout<<"\n";
	ll ans = 1;
	for(int i=1;i<g;i++){
		int len = bp[i]-bp[i-1];
		if(len%2){
			ans = 0;
			break;
		}
		ans = (1LL*ans*fac[len])%MOD;
		ans = (1LL*ans*inv(fac[len/2]))%MOD;	
		ans = (1LL*ans*inv(fac[(len/2)+1]))%MOD;	
	}
	cout<<ans<<"\n";
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	fac[0]=1;
	for(int i=1;i<=2*N;i++){
		fac[i] = (1LL*i*fac[i-1])%MOD;
	}
	while(t--){
		solve();
	}

	return 0;
}
