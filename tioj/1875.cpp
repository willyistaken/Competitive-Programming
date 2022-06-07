#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n;
	while(cin>>n){
		if(n>600000000){
			cout<<n-1<<endl;	
			continue;
		}
		int r = n;
		for(int i=2;i*i<=n;i++){
			if(n%i==0){
				while(n%i==0){
					n/=i;	
				}
				r -= r/i;
			}
		}
		if(n>1){//n is prime
			r -= r/n;
		}
		cout<<r<<endl;
		// phi(n) = n*(1-1/p1)*(1-1/p2)......
	}
	
	return 0;
}
