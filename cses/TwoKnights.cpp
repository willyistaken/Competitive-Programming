#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


void solve(int n){
	ll f = 1LL*n*n*(n*n-1)/2;
	f-= 4LL*(n-2)*(n-1);
	cout<<f<<"\n";
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++) solve(i);
	return 0;
}
