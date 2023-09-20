#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


const int MOD = 998244353;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	vector<int> v;
	for(int i=0;i<n;i++){
		int a,b;cin>>a>>b;
		for(int j=0;j<b;j++) v.push_back(a);
	}
	int c = v.size();
	ll ans = 0;
	map<int,ll> mp;
	map<int,ll> mp2;
	for(int j=0;j<v.size();j++){
		mp[v[j]]+=0;
		mp2[v[j]]+=0;
		for(int i=0;i<(1<<c);i++){
			ll sum = 0;	
			int d = 0;
			for(int k=0;k<c;k++){
				if((i>>k)&1){
					sum+=v[k];
					d = __gcd(d,v[k]);
					sum = sum%MOD;
				}
			}
			if(d!=1 && __gcd(d,v[j])==1){
				//cout<<j<<" "<<v[j]<<" "<<sum<<" "<<sum*sum<<"\n";
				mp[v[j]]+=sum;	
				mp2[v[j]]+=sum*sum;
				ans+=(1LL*sum*(sum+v[j]))%MOD;
				ans%=MOD;
			}
		}
	}
	for(auto i : mp){
		cout<<i.second<<"\n";
	}
	cout<<"\n";
	for(auto i : mp2){
		cout<<i.second<<"\n";
	}
	cout<<ans<<"\n";

	return 0;
}
