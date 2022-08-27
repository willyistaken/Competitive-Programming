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


int main(){
	int n,m;
	bitset<1005> inqueue;
	inqueue.set();
	n = R();
	m = R();
	vector<pair<int,int> > side[n+1];
	for(int i=0;i<m;i++){
		int a,b,w;
		a = R();
		b = R();
		w = R();
		side[b].push_back({a,-w});	
	}
	queue<int> wait;
	int dis[n+1];
	fill(dis,dis+n+1,1e6);
	for(int i=1;i<=n;i++) wait.push(i);
	int cnt[n+1]={0};
	while(wait.size()){
		int r = wait.front();
		wait.pop();
		inqueue[r]=0;
		for(auto i : side[r]){
			if(dis[i.first]>dis[r]+i.second){
				dis[i.first] = dis[r]+i.second;
				if(!inqueue[i.first]){
					wait.push(i.first);
					inqueue[i.first]=1;
					cnt[i.first]++;
					if(cnt[i.first]>n){
						puts("-1");
						return 0;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		assert(abs(dis[i])<=1000000);
		printf("%d\n",dis[i]);
	}

	return 0;
}
