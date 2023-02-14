#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


map<ll,ll> s;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n,x;cin>>n>>x;
	ll arr[n];
	ll cnt = 0;
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(s.count(x-arr[i]-arr[j])){
				cnt+=s[x-arr[i]-arr[j]];
			}
		}
		for(int k=i-1;k>=0;k--){
			s[arr[i]+arr[k]]++;
		}
	}
	cout<<cnt<<"\n";
	return 0;
}
