#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

void solve(){
	int n,m;cin>>n>>m;
	vector<pair<vector<int>,int>> a(n);

	for(int i=0;i<n;i++){
		a[i].first.resize(m);
		for(int j=0;j<m;j++){
			int g;
			cin>>g;
			g--;
			a[i].first[g]=j;
		}
		a[i].second = i;
	}
	sort(a.begin(),a.end());
	vector<int> ans(n,0);
	for(int i=0;i<n;i++){
		vector<int> k(m,0);
		for(int j=0;j<m;j++){
			k[a[i].first[j]]=j;
		}
		int b  = upper_bound(a.begin(),a.end(),make_pair(k,0))-a.begin();
		b--;
		int c = b+1;
		b = max(0,b);
		c = min(c,n-1);
		int pos = a[i].second;
		for(;ans[pos]<m;ans[pos]++){
			if(a[b].first[ans[pos]]!=k[ans[pos]]) break;
		}
		int g = 0;
		for(;g<m;g++){
			if(a[c].first[g]!=k[g]) break;
		}
		ans[pos] = max(ans[pos],g);
	}
	for(int i=0;i<n;i++) cout<<ans[i]<<" ";
	cout<<"\n";
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
