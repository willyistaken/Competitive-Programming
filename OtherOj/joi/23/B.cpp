#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


struct segtree{
	vector<ll> arr;
	int n;
	bool type = 0;
	void init(int s,bool t){
		type = t;
		if(type) arr.resize(2*s,-1e10);
		else arr.resize(2*s,1e10);
		n = s;
	}
	ll minmax(ll a,ll b){
		return (type)?(max(a,b)):(min(a,b));
	}
	void modify(int ind,ll v){
		ind+=n;
		while(ind){
			//cout<<type<<"|"<<ind<<":"<<arr[ind]<<"v.s"<<v<<": win:";
			arr[ind] = minmax(arr[ind],v);
			//cout<<arr[ind]<<"\n";
			ind>>=1;
		}
	}
	ll query(int l,int r){
		l+=n;r+=n;
		ll ans = (type)?(-1e10):(1e10);
		while(r>l){
			if(l&1) ans = minmax(ans,arr[l++]);
			if(r&1) ans = minmax(ans,arr[--r]);
			l>>=1;r>>=1;
		}
		return ans;
	}
};



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;	
	vector<int> x(n);
	vector<int> e(n);
	vector<int> d(n);
	vector<int> order(n);
	for(int i=0;i<n;i++){
		cin>>x[i]>>e[i];
		d[i]=x[i];
		order[i]=i;
	}
	sort(d.begin(),d.end());
	d.resize(unique(d.begin(),d.end())-d.begin());
	sort(order.begin(),order.end(),[&](const int a,const int b){return e[a]>e[b];});
	segtree pre;segtree suf;	
	pre.init(d.size(),1);
	suf.init(d.size(),0);
	int cnt = 0;
	int rb = d.size();
	for(int i=0;i<n;i++){
		int p = order[i];
		int loc = lower_bound(d.begin(),d.end(),x[p])-d.begin();
		ll premax = pre.query(0,loc+1);
		ll sufmin = suf.query(loc,rb);
		//cout<<premax<<" "<<sufmin<<"\n";
		if(premax>=x[p]+e[p] || sufmin<=x[p]-e[p]) continue;
		else{
			cnt++;
			pre.modify(loc,x[p]+e[p]);
			suf.modify(loc,x[p]-e[p]);
		}
		//cout<<pre.query(0,rb)<<" "<<suf.query(0,rb)<<"\n";
	}
	cout<<cnt<<"\n";
	return 0;
}
