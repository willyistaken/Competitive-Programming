#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
struct bit{
	vector<ll> arr;
	int n;
	void init(int s){
		arr.resize(s+1,0);
		n = s;
	}

	void add(int i,ll v){
		while(i<=n){
			arr[i]+=v;
			i+=(i&-i);
		}
	}
	ll query(int i){
		ll sum = 0;
		while(i){
			sum+=arr[i];
			i-=(i&-i);
		}
		return sum;
	}
};

bit b1;
bit b2;

void add(int l,int r,ll v){
	b1.add(l,v);
	b1.add(r+1,-v);
	b2.add(l,-(l*v));
	b2.add(r+1,(r+1)*v);
}

ll query(int l,int r){
	ll s = b1.query(r)-b1.query(l-1);
	ll st = b2.query(r)-b2.query(l-1);	
	st+=s*(r+1);
	st+=b1.query(l-1)*(r-l+1);			
	return st;
}

const int N  =5e5+5;

int dep[N];
int in[N];
int out[N];
vector<int> depset[N];
int t;
vector<int> side[N];
void dfs(int cur,int p){
	dep[cur] = dep[p]+1;
	in[cur]=++t;
	depset[dep[cur]].push_back(in[cur]);
	for(auto i : side[cur])	{
		if(!dep[i]) dfs(i,cur);
	}
	out[cur]=++t;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	b1.init(n);
	b2.init(n);
	int power[n+1];	
	for(int i=1;i<=n;i++) cin>>power[i];
	for(int i=2;i<=n;i++){
		int p;cin>>p;
		side[p].push_back(i);
	}
	dfs(1,0);
	int start[n+1];
	start[1]=1;
	for(int i=2;i<=n;i++){
		start[i] = start[i-1]+depset[i-1].size();	
		if(depset[i].empty()) break;
	}
	for(int i=1;i<=n;i++){
		int g = lower_bound(depset[dep[i]].begin(),depset[dep[i]].end(),in[i])-depset[dep[i]].begin();
		add(start[dep[i]]+g,start[dep[i]]+g,power[i]);
	}
	ll ans = 0;
	ll ans1e6 = 0;
	while(q--){
		ll u,v,w,x,y,z;cin>>u>>v>>w>>x>>y>>z;
		ll power = ((u*ans1e6)+v)%1000000;
		ll depth = ((w*ans)+x)%n;
		ll node = (((y*ans)+z)%n)+1;
		depth+=dep[node]; 
		int l = lower_bound(depset[depth].begin(),depset[depth].end(),in[node])-depset[depth].begin();
		int r = upper_bound(depset[depth].begin(),depset[depth].end(),out[node])-depset[depth].begin();
		r--;
		l+=start[depth];
		r+=start[depth];
		add(l,r,power);
		ans = query(l,r);
		cout<<ans<<"\n";
		ans1e6 = ans%1000000;
		ans%=n;
	}
	return 0;
}
