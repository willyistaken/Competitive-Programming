#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


int check(int k){
	cout<<"? "<<k;
	for(int i=1;i<=k;i++) cout<<" "<<i;
	cout<<endl;
	int ans;cin>>ans;
	return ans;
}

void solve(){
	int n;cin>>n;
	vector<ll> sum(n+1,0);
	for(int i=1;i<=n;i++){
		int a;cin>>a;
		sum[i]=sum[i-1]+a;
	}
	int r = n+1;
	int l = 0;
	while(r-l>1){
		int mid = (l+r)/2;
		ll g = check(mid);
		if(g>sum[mid]) r=mid;
		else l = mid;
	}
	cout<<"! "<<r<<endl;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
