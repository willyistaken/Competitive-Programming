#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,t,a,b;cin>>n>>t>>a>>b;
	a-=b;
	vector<ll> k(n+1);
	for(int i=1;i<=n;i++) cin>>k[i];
	for(int i=1;i<=n;i++){
		k[i]+=k[i-1];
	}
	ll maxn = 0;
	for(int i=1;i<=n;i++){
		if(t<i*b) break;
		int g = t-i*b;	
		int f = g/a;
		maxn = max(maxn,k[i]-k[max(0,i-f)]);
	}
	cout<<maxn<<"\n";


	return 0;
}
