#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

void solve(){
	int n;cin>>n;
	ll ans = 0;
	bool haszero = 0;
	bool previszero = 0;
	ll sum = 0;
	map<ll,int> stuff;
	int maxn = 0;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		if(a==0){
			if(previszero==0) {
				if(haszero) ans+=max(maxn,stuff[0]+1);	
				else ans+=maxn;
			}
			if(previszero==1) ans++;
			haszero = 1;
			previszero = 1;
			sum=0;
		}else{
			if(haszero==0){
				sum+=a;
				if(sum==0) ans++;
			}else if(previszero){
				stuff.clear();	
				maxn = 0;
				sum = 0;
				sum+=a;
				stuff[sum]++;
				maxn = max(stuff[sum],maxn);
			}else{
				sum+=a;
				stuff[sum]++;
				maxn = max(stuff[sum],maxn);
			}
			previszero  =0;
		}
	}
	if(previszero==0) {
			if(haszero) ans+=max(maxn,stuff[0]+1);	
			else ans+=maxn;
	}
	if(previszero==1) ans++;
	haszero = 1;
	previszero = 1;
	sum=0;
	cout<<ans<<"\n";
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--) solve();

	return 0;
}
