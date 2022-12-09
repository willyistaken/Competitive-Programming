#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k;cin>>n>>k;
	pair<int,int> movie[n];
	for(int i=0;i<n;i++) cin>>movie[i].second>>movie[i].first;
	sort(movie,movie+n);
	map<int,int> s;
	s[0]= k;
	int ans = 0;
	for(int i=0;i<n;i++){
		auto it = s.lower_bound(-movie[i].second);
		if(it!=s.end()){
			ans++;
			int g = it->first;
			s[g]--;
			if(s[g]==0) s.erase(g);
			s[-movie[i].first]++;
		}
	}
	cout<<ans<<"\n";
}
