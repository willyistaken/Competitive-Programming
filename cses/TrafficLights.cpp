#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int x,n;cin>>x>>n;
	set<int> seg;
	int ans = x;
	map<int,int> cnt;
	seg.insert(x);
	seg.insert(0);
	cnt[x]=1;
	for(int i=0;i<n;i++){
		int p;cin>>p;
		auto it = seg.lower_bound(p);		
		if(*it==p) continue;
		cnt[*it-p]++;
		cnt[p-*(--it)]++;
		++it;
		cnt[*(it)-*(--it)]--;
		if(cnt[*(++it)-*(--it)]==0) cnt.erase(*(++it)-*(--it));
		seg.insert(p);
		cout<<(--cnt.end())->first<<"\n";
	}
	return 0;
}
