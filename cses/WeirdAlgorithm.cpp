#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n;cin>>n;
	if(n==1){
		cout<<1<<"\n";
		return 0;
	}
	do{
		cout<<n<<" ";
		if(n%2) n = 3*n + 1;
		else n>>=1;
	}while(n!=1);
	cout<<1<<"\n";
	return 0;
}
