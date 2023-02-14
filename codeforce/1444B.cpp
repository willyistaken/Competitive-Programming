#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


const int MOD =998244353;

ll inv(ll a){
	int p = MOD-2;
	ll r = 1;
	while(p){
		if(p&1) r = (r*a)%MOD;
		a = (a*a)%MOD;
		p>>=1;
	}
	return r;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int arr[2*n];
	for(int i=0;i<2*n;i++) cin>>arr[i];
	sort(arr,arr+2*n);
	ll sum = 0;
	for(int i=n;i<2*n;i++) sum+= arr[i]-arr[i-n];
	sum = sum%MOD;
	ll nf = 1;	
	ll r = 1;
	for(int i=1;i<=2*n;i++){
		r = (r*i)%MOD;
		if(i==n) nf=r;
	}
	ll cn = (r*inv((nf*nf)%MOD))%MOD;
	cout<<(sum*cn)%MOD<<"\n";
	return 0;
}
