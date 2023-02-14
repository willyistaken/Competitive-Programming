#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n,m;cin>>n>>m;
	if(2*m==n*(n-1)) cout<<0<<"\n";
	else cout<<n<<"\n";
	return 0;
}
