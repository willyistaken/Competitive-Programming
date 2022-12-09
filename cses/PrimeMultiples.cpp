#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n;cin>>n;
	int k;cin>>k;
	ll sum = 0;
	ll prime[k];
	for(int i=0;i<k;i++) cin>>prime[i];
	for(int i=1;i<(1<<k);i++){
		int cnt=0;
		ll mprime=1;
		for(int j = 0;j<k;j++){
			if((i>>j) & 1) {
				cnt++;
				if(mprime>(n/prime[j]))	mprime = n+1;
				else{
					mprime*=prime[j];
				}
			}
		}
		mprime = n/mprime;
		if(cnt%2==0) mprime = -mprime;
		sum+=mprime;
	}
	cout<<sum<<"\n";
	return 0;
}
