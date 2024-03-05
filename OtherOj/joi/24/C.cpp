#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,L;cin>>n>>L;	
	int pos[n];
	for(int i=0;i<n;i++) cin>>pos[i];
	int q;cin>>q;
	while(q--){
		int s,g,t;cin>>s>>g>>t;
		bool y = 0;
		int now = g;
		vector<bool> in(n,0);
		ll ans = 0;
		for(int gg=0;gg<n;gg++){
			pair<int,int> minn = {1e9,-1};
			for(int i=0;i<n;i++){
				if(in[i]) continue;
				minn = min(make_pair(abs(now-pos[i]),i),minn);
			}
			ans+=(n-gg+1)*minn.first;
			now = pos[minn.second];
			in[minn.second]=1;
		}
		ans+=abs(now-s);
		if(ans+n<=t) cout<<"Yes\n";
		else cout<<"No\n";
	}
	

	return 0;
}
