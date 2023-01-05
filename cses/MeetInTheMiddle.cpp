#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,x;cin>>n>>x;
	if(n==1){
		int a;cin>>a;
		cout<<(a==x)<<"\n";
		return 0;
	}
	int f = n/2;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	unordered_map<ll,int> mp;
	for(int i=0;i<(1<<f);i++){
		ll sum = 0;
		for(int j=0;j<f;j++){
			if((i>>j)&1) sum+=arr[j];
		}
		mp[sum]++;
	}
	int s = n-f;
	ll ans = 0;
	for(int i=0;i<(1<<s);i++){
		ll sum = 0;
		for(int j=0;j<s;j++){
			if((i>>j)&1) sum+=arr[f+j];
		}
		if(mp.count(x-sum)) ans+=mp[x-sum];
	}
	cout<<ans<<"\n";
	return 0;
}
