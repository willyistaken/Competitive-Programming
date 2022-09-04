#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::

const int MOD = 1e9+7;


int power(int a,int p){
	int r=1;
	while(p){
		if(p&1) r = (1LL*r*a)%MOD;
		a = (1LL*a*a)%MOD;
		p>>=1;
	}
	return r;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k;cin>>n>>k;
	if(k>=n) cout<<power(2,n)<<"\n";
	else{
		int sum=1;
		int prev = 1;
		for(int i=1;i<=k;i++){
			prev = (1LL*prev*(n-i+1))%MOD;
			prev = (1LL*prev*power(i,1e9+5))%MOD;
			sum = (sum+prev)%MOD;
		}
		cout<<sum<<"\n";
	}

	return 0;
}
