#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	vector<pair<ll,ll>> arr(n+1);
	for(int i=1;i<=n;i++){
		int a;cin>>a;
		ll cnt =1;
		while(a%2==0){
			a/=2;
			cnt*=2;
		}
		arr[i] = {a,cnt};
	}
	for(int i=1;i<=n;i++){
		arr[i].second+=arr[i-1].second;
	}
	int q;cin>>q;
	int head = 0;
	while(q--){
		ll x;cin>>x;
		while(arr[head].second<x) head++;
		cout<<arr[head].first<<"\n";
	}
	return 0;
}
