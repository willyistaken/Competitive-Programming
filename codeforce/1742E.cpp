#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


void solve(){
	int n;cin>>n;
	int q;cin>>q;
	ll sum[n+1];
	ll maxn[n+1];
	memset(sum,0,sizeof(sum));
	memset(maxn,0,sizeof(maxn));
	for(int i=1;i<=n;i++){
		int a;cin>>a;
		sum[i] = sum[i-1]+a;
		maxn[i] = max(maxn[i-1],(ll)a);
	}
	while(q--){
		int k;cin>>k;
		int l = 0;int r = n+1;
		while(r-l>1){
			int mid = (r+l)/2;
			if(maxn[mid]<=k) l = mid;
			else r = mid;
		}
		cout<<sum[l]<<" ";
	}	
	cout<<"\n";
	return ;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
