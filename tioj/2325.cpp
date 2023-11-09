#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	vector<ll> arr(n+1);
	for(int i=1;i<=n;i++) cin>>arr[i];
	vector<ll> oddsum(n+1);
	vector<ll> evensum(n+1);
	for(int i=1;i<=n;i++){
		if(i&1) oddsum[i]+=arr[i];
		else evensum[i]+=arr[i];
		oddsum[i]+=oddsum[i-1];
		evensum[i]+=evensum[i-1];
	}
	while(q--){
		int a,p;cin>>a>>p;
		int l = 0;int r = n+1;
		while(r-l>1){
			int mid = (l+r)/2;
			if(oddsum[mid]+evensum[mid]>=a) r = mid;
			else l= mid;
		}
		if(l>=p){
			cout<<a-oddsum[p]-evensum[p]<<"\n";
			continue;
		}
		a-=oddsum[l]+evensum[l];
		if(p&1){
			ll ans = oddsum[p]-oddsum[l];
			ans-=evensum[p]-evensum[l];
			if(r&1) ans-=a;
			else ans+=a;
			cout<<ans<<"\n";
		}else{
			ll ans = evensum[p]-evensum[l];
			ans-=oddsum[p]-oddsum[l];
			if(r&1) ans+=a;
			else ans-=a;
			cout<<ans<<"\n";
		}
	}

	return 0;
}
