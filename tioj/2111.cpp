#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int MOD = 1e9+7;
const int M = 1e9+6;
const int N = 3e6+5;
int isp[N];
vector<int> prime;
void init(){
	isp[1]=1;
	for(int i=2;i<N;i++){
		if(isp[i]==0){
			prime.push_back(i);
			for(int j=i;j<N;j+=i) isp[j]=i;
		}
	}
}

ll pow(int a,ll p){
	ll r = 1;
	while(p){
		if(p&1)	r = (r*a)%MOD;
		a = (1LL*a*a)%MOD;
		p>>=1;
	}
	return r;
}


void solve(){
	int n;cin>>n;
	//assert(n<4e5);
	ll ans = 1;
	for(auto p : prime){
		if(p>n) break;
		ll h = p;
		vector<ll> cnt;			
		cnt.push_back(n);
		while(h<=n){
			cnt.push_back(n/h);
			h*=p;
		}
		cnt.push_back(0);
		ll gcm=0;
		ll lcd=0;
		for(int i=0;i<cnt.size()-1;i++){
	//		cout<<cnt[i]<<"cnt\n";
			ll gw = ((1LL*(1LL*(cnt[i]-cnt[i+1])*(cnt[i+1])%M)*(2*cnt[0]-cnt[i+1]))%M)+((1LL*(cnt[i]-cnt[i+1])%M)*(1LL*(2*cnt[0]-cnt[i]-cnt[i+1])*(cnt[i])%M))%M;
			ll lw = (((cnt[i]-cnt[i+1])*((1LL*cnt[0]*cnt[0]-1LL*cnt[i]*cnt[i])%M))%M+1LL*((1LL*cnt[i]*cnt[i]-1LL*cnt[i+1]*cnt[i+1])%M)*(cnt[0]-cnt[i+1])%M);
			gcm=(gcm+(1LL*(i)*gw%M))%M;
	//		cout<<gw<<"g\n";
			lcd=(lcd+(1LL*(i)*lw%M))%M;
	//		cout<<lw<<"l\n";
		}
		//cout<<gcm<<" "<<lcd<<":"<<p<<"\n";
		ans = ans*pow(p,(gcm+lcd)%M)%MOD;
	}
	cout<<ans<<"\n";
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	init();
	int T;cin>>T;
	while(T--){
		solve();
	}

	return 0;
}


