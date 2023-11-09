#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
int n;
vector<ll> x;

void solve(){
	int a;cin>>a;
	int k = lower_bound(x.begin(),x.end(),a)-x.begin();
	if(abs(x[k-1]-a)<=abs(x[k]-a)) k--;
	ll ans = 0;
	ans+=abs(x[k]-a);
	int cur = k;
	int l = k;int r = k;
	while(l!=1 || r!=n){
		if(abs(x[l-1]-x[cur])<=abs(x[r+1]-x[cur])) {ans+=(abs(x[l-1]-x[cur]));cur=l-1;l--;}
		else {ans+=(abs(x[r+1]-x[cur]));cur=r+1;r++;}
	}
	cout<<ans<<"\n";
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	x.resize(n+2);
	x[0] = -1e15;
	x[n+1] = 1e15;
	for(int i=1;i<=n;i++) cin>>x[i];
	int q;cin>>q;
	while(q--){
		solve();
	}
	return 0;
}
