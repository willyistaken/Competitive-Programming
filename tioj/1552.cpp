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


int n,m;
const int MAXN = 1e6+5;
vector<pair<int,ll> > side[MAXN];


int main(){
	n = R();m = R();
	while(m--){
		int a,b;ll w;a = R();b = R(); w =R();
		side[a].push_back({b,w});
	}
	priority_queue<pair<ll,pair<int,int> >,vector<pair<ll,pair<int,int> > >,greater<pair<ll,pair<int,int> >> > pq;
	ll dis[MAXN];
	fill(dis,dis+MAXN,1e18);
	dis[1]=0;
	int p[MAXN]={0};
	pq.push({0,{1,-1}});
	while(pq.size()){
		auto temp = pq.top();pq.pop();
		ll d = temp.first;
		pair<int,int> cur = temp.second;
		if(d>dis[cur.first] || p[cur.first]) continue;
		for(auto i : side[cur.first]){
			if(d+i.second<dis[i.first]){
				dis[i.first]=d+i.second;
				pq.push({dis[i.first],{i.first,cur.first}});
			}
		}
		p[cur.first]=cur.second;
	}
	printf("%lld\n",dis[n+1]);
	stack<int> ans;
	int r = n+1;
	while(r>0){
		ans.push(r);
		r = p[r];
	}
	while(ans.size()){
		printf("%d",ans.top());printf(((ans.size()==1)?("\n"):("-")));
		ans.pop();
	}
	return 0;
}
