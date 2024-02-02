#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int a = 1;
	int b = 2;
	int mod;cin>>mod;
	for(int i=0;i<100;i++){
		int c = (2*b+a)%mod;	
		a = b;
		b = c;
		cout<<b<<" ";
	}
	cout<<"\n";

	return 0;
}
