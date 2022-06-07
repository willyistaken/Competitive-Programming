#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int const MOD = 1000000009;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n;cin>>n;
	ll sum=0;
	for(ll i=1;i<=n;i++){
		ll next =n/(n/i);
		ll right = (next%MOD)*((next+1)%MOD)%MOD;
		ll left = (i%MOD)*((i-1)%MOD)%MOD;
		sum = (sum + ((n/i)%MOD)*(right-left+MOD))%MOD;
		i=next;
	}
	ll sqaure = (n%MOD)*(n%MOD) %MOD;
	cout<<((sqaure-sum*500000005%MOD)+MOD)%MOD<<endl;
	return 0;
	//500000005 is the mod inverse of 2
}
