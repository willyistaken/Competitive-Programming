#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int MOD = 998244353;


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	vector<int> arr;
	for(int i=0;i<n;i++){
		int v,b;cin>>v>>b;
		for(int i=0;i<b;i++) arr.push_back(v);
	}
	if(arr.size()>18) return 0;	
	int g = arr.size() ;
	ll ans = 0;
	for(int i=1;i<(1<<g);i++){
		bool check = 1;
		int cd =0;

		ll sum=0;
		for(int j=0;j<g;j++){
			if(i>>j & 1){
				if(!cd) cd = arr[j];
				else cd = __gcd(cd,arr[j]);
				sum+=arr[j];
			}
		}
		if(cd!=1){
		for(int j=0;j<g;j++){
				if(!((i>>j)&1)){
					if(__gcd(cd,arr[j])==1){
						ans+=(1LL*(sum+arr[j])*arr[j])%MOD;
					}
				}
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
