#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


const int MOD = 1e9+7;

int inv(int a){
	ll r = 1;
	int  p =MOD-2;
	while(p){
		if(p&1) r = (1LL*r*a)%MOD;
		a = (1LL*a*a)%MOD;
		p>>=1;
	}
	return r;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	string s;cin>>s;
	int p = s.size();
	int m =0;
	for(auto i : s){
		if(i=='(') m++;
		else m--;
		if(m<0){
			cout<<"0\n";
			return 0;
		}
	}
	int k = m;
	if((n-p-m)%2 || (n-p-m)<0){
		cout<<0<<"\n";
		return 0;
	}
	n = (n-p-m)/2;
	ll c = 1;
	for(int i=1;i<=n;i++){
		c = (c*(2*i+k-1))%MOD;
		c = (c*(2*i+k))%MOD;
		int v = inv((1LL*i*(i+k+1))%MOD);
		c = (v*c)%MOD;
	}
	cout<<c<<"\n";
	return 0;
}
