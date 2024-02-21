#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct bit{
	vector<int> arr;
	int n;
	void init(int _n){
		n = _n;	
		arr.resize(n+1,0);
	}
	void add(int ind,int v){
		while(ind<=n){
			arr[ind]+=v;
			ind+=(ind&-ind);
		}
	}
	int query(int ind){
		int s=0;
		while(ind){
			s+=arr[ind];
			ind-=(ind&-ind);
		}
		return s;
	}
};

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	vector<int> h(n+1);
	for(int i=1;i<=n;i++) cin>>h[i];
	h[0]=0;
	vector<int> d;
	for(int i=0;i<=n;i++) d.push_back(h[i]);
	sort(d.begin(),d.end());
	d.resize(unique(d.begin(),d.end())-d.begin());
	for(int i=0;i<=n;i++){
		h[i] = lower_bound(d.begin(),d.end(),h[i])-d.begin();
	}
	vector<vector<int> > add(d.size());
	vector<vector<int> > remove(d.size());
	for(int i=1;i<=n;i++){
		if(h[i-1]<=h[i]-1){
			add[h[i-1]].push_back(i);
			remove[h[i]-1].push_back(i);
		}
	}
	bit B;		
	B.init(n);
	vector<int> ans(q);
	vector<vector<int> > Qs(d.size());
	vector<pair<int,int> > Q(q);
	for(int i=0;i<q;i++){
		cin>>Q[i].first>>Q[i].second;
		int t;cin>>t;
		t = upper_bound(d.begin(),d.end(),t)-d.begin();
		t--;
		Qs[t].push_back(i);
	}
	for(int i=0;i<d.size();i++){
		for(auto e : add[i]){
			B.add(e,1);
		}
		for(auto e : Qs[i]){
			int l = Q[e].first;
			int r = Q[e].second;
			ans[e] = B.query(r)-B.query(l-1);
			if(B.query(l)-B.query(l-1)==0 && h[l]>i) ans[e]++;
		}
		for(auto e : remove[i]){
			B.add(e,-1);
		}
	}
	for(int i=0;i<q;i++) cout<<ans[i]<<"\n";
	return 0;
}
