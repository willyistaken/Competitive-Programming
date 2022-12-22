#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 2e5+5;
pair<int,int> ord[N];
int t;
vector<int> side[N];
struct BIT{
	vector<ll> arr;
	int _n;
	void init(int s){
		arr.resize(s+1,0);
		_n = s;
	}
	void modify(int ind,ll v){
		while(ind<=_n){
			arr[ind]+=v;
			ind+=(ind & -ind);
		}
	}
	ll query(int ind){
		ll ans = 0;
		while(ind){
			ans+=arr[ind];
			ind-=(ind & -ind);
		}
		return ans;
	}

};

void dfs(int v){
	ord[v].first=++t;	
	for(auto i : side[v]){
		if(!ord[i].first) dfs(i);
	}
	ord[v].second=t;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	int w[n+1];
	for(int i=1;i<=n;i++) cin>>w[i];
	BIT bit;
	bit.init(n);
	for(int i=1;i<n;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
	}
	dfs(1);
	for(int i=1;i<=n;i++){
		bit.modify(ord[i].first,w[i]);
	}
	
	while(q--){
		int ty;cin>>ty;
		/*for(int i=1;i<=2*n;i++){
			cout<<bit.query(i)-bit.query(i-1)<<" ";
			cout<<"\n";
		}*/
		if(ty==1){
			int x,v;cin>>x>>v;
			bit.modify(ord[x].first,-w[x]);
			w[x]=v;
			bit.modify(ord[x].first,w[x]);
		}else{
			int v;cin>>v;
			cout<<bit.query(ord[v].second)-bit.query(ord[v].first-1)<<"\n";
		}
	}
	return 0;
}
