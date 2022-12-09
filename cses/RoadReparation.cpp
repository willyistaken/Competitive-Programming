#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
int cnt = 0;
struct MST{
	struct dsu{
		vector<int> pa;
		void init(int n){
			pa.resize(n);
			for(int i=0;i<n;i++) pa[i]=i;
		}
		int query(int a){
			return (pa[a] = (pa[a]==a)?(pa[a]):(query(pa[a])));
		}
		void join(int a,int b){
			pa[query(a)] = query(b);
		}
	} DSU;
	struct e{
		int a,b;
		int w;
	};
	vector<e> es;
	void init(int s){
		DSU.init(s);
	}
	void add_edge(int a,int b,int w){
		es.push_back({a,b,w});
	}
	ll mst(){
		sort(es.begin(),es.end(),[](const e &a,const e &b){return a.w<b.w;});
		ll sum = 0;	
		for(auto i : es){
			if(DSU.query(i.a)!=DSU.query(i.b)){
				sum+=i.w;
				DSU.join(i.a,i.b);
				cnt++;
			}
		}
		return sum;
	}
};




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	MST mst;
	int n,m;cin>>n>>m;
	mst.init(n);
	while(m--){
		int a,b,w;cin>>a>>b>>w;
		a--;b--;
		mst.add_edge(a,b,w);
	}
	ll ans = mst.mst();
	if(cnt==n-1) cout<<ans<<"\n";
	else cout<<"IMPOSSIBLE\n";

	return 0;
}

