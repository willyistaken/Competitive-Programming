#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	pair<int,int> seg[n];
	for(int i=0;i<n;i++) cin>>seg[i].second>>seg[i].first;
	sort(seg,seg+n);
	int ans = 1;
	int prev = 0;
	for(int i=1;i<n;i++){
		if(seg[i].second>=seg[prev].first) {
			ans++;
			prev = i;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
