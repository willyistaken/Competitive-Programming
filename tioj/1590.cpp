#include<bits/stdc++.h>
using namespace std;
#define ll long long



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	vector<pair<int,int> > cs;
	for(int i=0;i<n;i++){
		int s,c;cin>>s>>c;
		cs.push_back({s+c,s});
	}
	sort(cs.begin(),cs.end());
	int maxn[n];
	maxn[0] = cs[0].second;
	for(int i=1;i<n;i++){
		maxn[i]= max(maxn[i-1],cs[i].second);
	}
	for(int i=0;i<m;i++){
		int q;cin>>q;
		int it = lower_bound(cs.begin(),cs.end(),make_pair(q+1,-1))-cs.begin();
		it-=1;
		if(it<0) cout<<-1<<endl;
		else cout<<maxn[it]<<endl;
	}
	return 0;
}
