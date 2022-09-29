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

const int mod = 1073741824;
struct edge{
	int to;
	int next;
};
vector<int> head;
vector<edge> e;
vector<int> rhead;
vector<edge> re;
vector<int> dp;
stack<int> seq;
bitset<10005> vis;
void dfs(int u){
	vis[u]=1;
	for(int v=head[u];v!=-1;v = e[v].next){
		if(!vis[e[v].to]) dfs(e[v].to);
	}
	seq.push(u);
}

int main(){
	int n=R();
	int m=R();
	head.resize(n,-1);rhead.resize(n,-1);
	dp.resize(n,0);
	e.resize(m);re.resize(m);
	for(int i=0;i<m;i++){
		int a,b;a=R();b=R();
		a--;b--;
		e[i].to = b;
		e[i].next = head[a];
		head[a] = i;
		re[i].to = a;
		re[i].next = rhead[b];
		rhead[b] = i;
	}
	int v,d;
	v =R();d=R();
	v--;d--;			
	dp[v]=1;
	vis.reset();
	for(int i=0;i<n;i++){
		if(!vis[i]) dfs(i);
	}
	while(seq.size()){
		int now = seq.top();seq.pop();
		for(int v = rhead[now];v!=-1;v=re[v].next){
			dp[now]+=dp[re[v].to];
			dp[now] = (dp[now]>=mod)?(dp[now]-=mod):(dp[now]);
		}
	}
	printf("%d\n",dp[d]);
	return 0;
}
