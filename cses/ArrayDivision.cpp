#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
int n,k;
vector<int> arr;

bool check(ll m){
	ll cur = 0;
	int cnt = 0;
	for(int i=0;i<n;i++){
		if(arr[i]>m) return 0;
		if(cur+arr[i]>m){
			cnt++;	
			cur = arr[i];
		}else{
			cur+=arr[i];
		}
	}
	cnt++;
	return (cnt<=k);
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	arr.resize(n);
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	ll l = 0;ll r = 1e18;		
	while(r-l>1){
		ll m = (l)+(r-l)/2;
		if(check(m)) r= m;
		else l = m;
	}
	cout<<r<<"\n";
	return 0;
}
