#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


bool pl(ll g){
	ll a = g;
	vector<int> arr;	
	while(g){
		arr.push_back(g%10);
		g/=10;
	}
	ll f = 0;
	for(auto i : arr){
		f*=10;
		f+=i;
	}
	
	if(f==a){
		return 1;
	}
	else return 0;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n;cin>>n;
	ll maxn = 1;
	for(int i=1;(1LL*i*i*i)<=n;i++){
		ll k = (1LL*i*i*i);
		if(pl(k)) maxn = max(k,maxn);
	}
	cout<<maxn<<"\n";
			

	return 0;
}
