#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

int q,p;

int pow(int a,int n){
	int r = 1;
	while(n){
		if(n&1) r = (1LL*r*a)%p;
		a = (1LL*a*a)%p;
		n>>=1;
	}
	return r;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);	
	cin>>q>>p;
	while(q--){
		int x,k;cin>>x>>k;
		x= p-x;
		cout<<pow(x,k)<<"\n";
	}

	return 0;
}
