#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::

ll n,m;

vector<int> prime;


void init(){
	bitset<10000005> notprime;
	notprime.reset();
	for(int i=2;i<=1e7;i++){
		if(!notprime[i]){
			prime.push_back(i);
			for(int j= i;j<=1e7;j+=i) notprime[j]=1;
		}
	}
}

ll pow(ll a,ll p,ll mod){
	ll r = 1;
	while(p){
		if(p&1) r = ((__int128)r*a)%mod;
		a = ((__int128)a*a)%mod;
		p>>=1;
	}
	return r;
}

vector<int> factor(int g){
	vector<int> f;
	for(int i=1;i<=sqrt(g);i++){
		if(g%i==0){
			f.push_back(i);
			f.push_back(g/i);
		}
	}
	sort(f.begin(),f.end());
	return f;
}
pair<ll,ll> calc(int p,int cnt){
	ll mod = pow(p,cnt,1e18);
	if(n%p==0){
		ll r = 1;
		for(ll i=1;i<=mod;i++){
			r = ((__int128)r*n)%mod;
			if(r==0) return {i,1};
		}
	}else{
		ll mincy = 1e18;
		vector<int> f = factor(p-1);	
		ll g = 1;
		ll mod = pow(p,cnt,1e18);
		for(int k = 0;k<cnt;k++){
			for(auto v:f){
				if(pow(n,v*g,mod)==1){
					mincy = min(mincy,v*g);
				}
			}
			g = g*p;
		}
		return {0,mincy};
	}
	assert(1==0);
	return {0,0};
}



int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);	
	init();
	while(cin>>n>>m){
		n%=m;
		ll pre = 0;
		ll cycle = 1;
		for(auto i : prime){
			if(m%i==0){
				int p = i;
				int cnt=0;
				while(m%p==0){
					cnt++;
					m/=p;
				}
				pair<ll,ll> temp = calc(p,cnt);
				pre = max(pre,temp.first);
				cycle = ((__int128)cycle*temp.second)/__gcd(cycle,temp.second);
			}
		}
		cout<<pre<<" "<<cycle<<"\n";
	}
}
