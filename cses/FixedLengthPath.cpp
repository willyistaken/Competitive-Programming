#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 2e5+5;
vector<int> side[N];
bool pick[N];
int n,k;
int sz[N];
int cnt[N];

ll get(int v,int p,int d=1){
	if(d>k) return 0;
	ll ans = 0;
	ans+=cnt[k-d];
	for(auto i : side[v]){
		if(!pick[i] && i!=p){
			ans+=get(i,v,d+1);
		}
	}
	return ans;
}
int fill(int v,int p,int d=1){
	if(d>k) return 0;
	cnt[d]++;
	int maxn = d;
	for(auto i : side[v]){
		if(!pick[i] && i!=p){
			maxn= max(fill(i,v,d+1),maxn);
		}
	}
	return maxn;
}

int getsz(int v,int p=0){
	sz[v]=1;
	for(auto i : side[v]){
		if(!pick[i] && i!=p){
			sz[v]+=getsz(i,v);
		}
	}
	return sz[v];
}

int centroid(int ds,int v,int p=0){
	for(auto i : side[v]){
		if(!pick[i] && i!=p){
			if(sz[i]>ds){
				return centroid(ds,i,v);
			}
		}
	}
	return v;
}

ll ans(int v){
	int g = centroid(getsz(v)/2,v);
	pick[g]=1;
	ll r = 0;
	int maxnf = 0;
	for(auto i : side[g]){
		if(!pick[i]){
			r+=get(i,g);
			maxnf = max(maxnf,fill(i,g));
		}
	}
	r+=cnt[k];
	fill(cnt,cnt+maxnf+1,0);
	for(auto i : side[g]){
		if(!pick[i]) r+=ans(i);
	}
	return r;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=0;i<n-1;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
	}
	cout<<ans(1)<<"\n";
	return 0;
}
