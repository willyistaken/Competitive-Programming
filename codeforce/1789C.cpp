#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


void solve(){
	int n,m;cin>>n>>m;
	map<int,int> aptime;
	map<int,int> cnt;
	int arr[n+1];
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		aptime[arr[i]]=0;
	}
	for(int i=1;i<=m;i++){
		int p,v;cin>>p>>v;
		cnt[arr[p]]+=(i-aptime[arr[p]]);
		aptime[arr[p]] = m+1;
		aptime[v]=i;
		arr[p]=v;
	}
	for(auto k : aptime){
		cnt[k.first]+=m+1-k.second;
	}
	ll ans = 0;
	ll com = (1LL*(m+1)*m)/2;
	for(auto i : cnt){
		//cout<<i.first<<" "<<i.second<<"\n";
		int g = (m+1-i.second);
		ans+=com-(1LL*g*(g-1))/2;
	}
	cout<<ans<<"\n";
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
