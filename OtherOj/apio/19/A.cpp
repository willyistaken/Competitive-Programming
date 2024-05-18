#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
// observation 
// every thing is the same, actually
// it will probably be A/gcd(A,b+1)*B stuff,so basically lcm(A,B) 

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	ll A,B;
	cin>>n>>A>>B;
	ll A_g = A/__gcd(A,B+1);
	if(B>(1e18/A_g)){
		ll ans = 0;
		for(int i=0;i<n;i++){
			ll l,r;cin>>l>>r;
			ans+=r-l+1;
		}
		cout<<ans<<"\n";
		return 0;
	}
	ll M = B*A_g;
	map<ll,int> sum;
	for(int i=0;i<n;i++){
		ll l,r;cin>>l>>r;
		if(r-l+1>=M){
			sum[0]++;
			sum[M]--;
		}else{
			ll k = l%M;
			ll h = r%M;
			if(k<=h){
				sum[k]++;
				sum[h+1]--;
			}else{
				sum[k]++;
				sum[M]--;
				sum[0]++;
				sum[h+1]--;
			}
		}
	}
	sum[M]+=0;
	ll prev = 0;	
	int s=0;
	ll ans = 0;
	for(auto i : sum){
		if(s){
			ans+=(i.first-prev);
		}
		s+=i.second;
		prev = i.first;
	}
	cout<<ans<<"\n";
	return 0;
}

