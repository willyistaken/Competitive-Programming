#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n,k;cin>>n>>k;
	if(n>1000) return 0;
	vector<ll> S(n+1,0);
	for(int i=1;i<=n;i++){
		int a;cin>>a;
		S[i] = S[i-1]+a;
	}
	ll cnt = 0;
	for(int i=0;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(S[j]-S[i]<=k) cnt++;
		}
	}
	cout<<cnt<<"\n";
	return 0;
}
