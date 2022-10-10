#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::
#include <unistd.h>
inline char RC(){static char buf[65536],*p=buf,*q=buf;return p==q&&(q=(p=buf)+read(0,buf,65536))==buf?-1:*p++;}
inline int R(){
	int ans = 0; char c = RC(); bool minus = false;
	while((c < '0' or c > '9') and c != '-' and c != EOF) c = RC();
	if(c == '-') minus = true, c = RC();
	while(c >= '0' and c <= '9') ans = ans * 10 + (c ^ '0'), c = RC();
	return minus ? -ans : ans;
}


int n,q;
const int MAXN = 1000005;
struct e{
	int prev;
	int to;
};

pair<int,int> seq[MAXN];
e edge[MAXN];
int ee[MAXN];
int w[MAXN];
struct bit{
	int arr[MAXN];
	int s;
	void init(int k){
		s = k;
	}
	int query(int ind){
		int r = 0;
		while(ind){
			r+=arr[ind];
			ind -= (ind & -ind);
		}
		return r;
	}

	void add(int ind,int v){
		while(ind<=s){
			arr[ind]+=v;
			ind += (ind & -ind);
		}
	}
} fwk;
int t;
void dfs(int r){
	seq[r].first = ++t;
	for(int p = ee[r];p!=-1;p = edge[p].prev){
		dfs(edge[p].to);
	}
	fwk.add(seq[r].first,w[r]);
	seq[r].second = t;
}

int main(){
	n = R();q = R();
	fill(ee,ee+MAXN,-1);
	for(int i=0;i<n-1;i++){
		int a = R();int b = R();int m = R();
		edge[i].prev = ee[a];
		ee[a] = i;
		edge[i].to = b;
		w[b]=m;
	}
	fwk.init(n);
	dfs(0);
	/*for(int i=0;i<n;i++){
		cout<<i<<":"<<fwk.query(seq[i].second)-fwk.query(seq[i].first)<<"\n";
	}*/
	
	while(q--){
		int type = R();
		if(type){
			int r= R();
			printf("%d\n",2*(fwk.query(seq[r].second)-fwk.query(seq[r].first)));
		}else{
			int d=R();int m = R();
			fwk.add(seq[d].first,-w[d]);
			fwk.add(seq[d].first,m);
			w[d]=m;
		}
	}
	
	return 0;
}

// very very optimize
