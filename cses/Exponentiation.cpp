#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int MOD = 1e9+7;

int pow(int a,int b){
	int r=  1;
	while(b){
		if(b&1) r = (1LL*a*r)%MOD;
		a = (1LL*a*a)%MOD;
		b>>=1;
	}
	return r;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	while(n--){
		int a,b;cin>>a>>b;
		cout<<pow(a,b)<<"\n";
	}

	return 0;
}
