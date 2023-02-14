#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	if(n==3){
		cout<<2<<"\n";
		return 0;
	}
	ll r = 1;
	for(int i=0;i<n-2;i++){
		r = (r*2)%998244353;
	}
	cout<<r-1<<"\n";
	return 0;
}
