#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,q;
struct DSU{
	vector<int> arr;
	void init(){
		arr.resize(n+5);
		for(int i=0;i<n+5;i++) arr[i] = i;
	}

	int query(int a){
		return (arr[a]==a)?(arr[a]):(arr[a] = query(arr[a]));
	}

	void join(int a,int b){
		arr[query(a)] = query(b);
	}
} dsu;
const int N = 1e5+5;
vector<int> side[N];
bitset<N> vis;int dfromv[N];int ufromv[N];
int pa[N];
void getszd(int v){
	vis[v] = 1;
	bool ch = 0;
	for(auto i : side[v]){
		if(!vis[i]){
			pa[i] = v;
			ch=1;
			getszd(i);
			dfromv[v]= max(dfromv[i],dfromv[v]);
		}
	}
	dfromv[v]+=ch;
}

void getufromv(int v){
	vis[v] = 1;	
	if(pa[v]!=0){
		int maxn = 0;
		for(auto i : side[pa[v]]){
				if(i!=v && i!=pa[pa[v]]){
					maxn = max(dfromv[i]+1,maxn);
				}
		}
		maxn = max(maxn,ufromv[pa[v]]);
		ufromv[v] = maxn+1;
	}
	for(auto i : side[v]){
		if(!vis[i]) getufromv(i);
	}
}

int main(){	
		cin>>n>>m>>q;	
		cout<<fixed<<setprecision(10);
		dsu.init();
		for(int i=0;i<m;i++){
			int a,b;cin>>a>>b;
			dsu.join(a,b);	
			side[a].push_back(b);
			side[b].push_back(a);
		}
		vis.reset();
		for(int i=1;i<=n;i++){
			if(!vis[i]) getszd(dsu.query(i));
		}
		vis.reset();
		for(int i=1;i<=n;i++){
			if(!vis[i]) getufromv(dsu.query(i));
		}
		vector<int> tree[n+1];
		vector<ll> sum[n+1];
		for(int i=1;i<=n;i++){
			tree[dsu.query(i)].push_back(max(dfromv[i],ufromv[i]));
		}
		for(int i=1;i<=n;i++){
			sum[i].push_back(0);
			for(auto j : tree[i]){
				sum[i].push_back(j);
			}
			sort(tree[i].begin(),tree[i].end());
			sort(sum[i].begin(),sum[i].end());
			for(int j=1;j<sum[i].size();j++){
				sum[i][j] +=sum[i][j-1];
			}
		}
		map<pair<int,int> ,ll> ans;
		int B = sqrt(n);
		while(q--){
			int x,y;cin>>x>>y;
			x = dsu.query(x);
			y = dsu.query(y);
			if(x==y){
				cout<<-1<<"\n";
				continue;
			}
			if(ans.count(make_pair(min(x,y),max(x,y)))){
				cout<<((double)ans[make_pair(min(x,y),max(x,y))]) / ((double)tree[x].size()*tree[y].size())<<"\n";
			}else{

				if(tree[x].size()>tree[y].size()) swap(x,y);
				int maxd = max(tree[x].back(),tree[y].back());
				ll result = 0;	
				/*
				cout<<x<<":";
				for(auto i : tree[x]) cout<<i<<" ";
				cout<<"\n";
				
				cout<<y<<":";
				for(auto i : tree[y]) cout<<i<<" ";
				cout<<"\n";
				*/	
				for(auto i : tree[x]){
					int pos=	lower_bound(tree[y].begin(),tree[y].end(),maxd-i-1)-tree[y].begin();
					result += 1LL*pos*maxd + (sum[y].back()-sum[y][pos]) + (1LL*(tree[y].size()-pos)*(i+1));
				}
				ans[make_pair(min(x,y),max(x,y))] = result;
				cout<<((double)ans[make_pair(min(x,y),max(x,y))])/ ((double)tree[x].size()*tree[y].size())<<"\n";
			}
		}
}


