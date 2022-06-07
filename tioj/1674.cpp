#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int const MOD = 1000000009;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n;cin>>n;
	ll sum=0;
	for(ll i=1;i<=n;i++){
		sum += n%i;
		sum = (sum>MOD) ? sum-MOD:sum;
	}
	cout<<sum<<endl;
	return 0;
}
