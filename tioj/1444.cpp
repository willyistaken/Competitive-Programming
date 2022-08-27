#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::
#include <unistd.h>
inline char RC(){static char buf[65536],*p=buf,*q=buf;return p==q&&(q=(p=buf)+read(0,buf,65536))==buf?-1:*p++;}
inline int R(){static char c;int a;while((c=RC())<'0');a=c^'0';while((c=RC())>='0')a*=10,a+=c^'0';return a;}

int n,m;
short subtreesize[5005];
short ptreesize[5005];
vector<short> side[5005];
int t;
short vis[5005];

void dfs1(int r){
	vis[r]=++t;
	for(auto i : side[r]){
		if(!vis[i]){
			dfs1(i);
			subtreesize[r] = max(subtreesize[r],(short)(1+subtreesize[i]));
		}
	}
}
void dfs2(int r,int from){
	for(auto i : side[from]){
		if(i!=r && vis[i]>vis[from]) ptreesize[r] = max((short)(2+subtreesize[i]),ptreesize[r]);	
	}
	ptreesize[r] = max((short)(1+ptreesize[from]),ptreesize[r]);
	for(auto i : side[r]){
		if(vis[i]>vis[r]) dfs2(i,r);
	}	
}

int main(){
	n = R();m = R();
	for(int i=0;i<m;i++){
		int a,b;a = R();b = R();
		side[a].push_back(b);
		side[b].push_back(a);
	}
	dfs1(1);
	ptreesize[0]=-1;
	dfs2(1,0);
	int mindis=INT_MAX;
	int maxdis = 0;
	for(int i=1;i<=n;i++){
		int dis = max(subtreesize[i],ptreesize[i]);
	//	cout<<subtreesize[i]<<","<<ptreesize[i]<<" ";
		mindis = min(dis,mindis);
		maxdis = max(dis,maxdis);
	}
	//cout<<"\n";
	for(int i=1;i<=n;i++){
		if(max(subtreesize[i],ptreesize[i])==mindis) printf("%d ",i);
	}
	puts("");
	for(int i=1;i<=n;i++){
		if(max(subtreesize[i],ptreesize[i])==maxdis) printf("%d ",i);
	}
	puts("");

	
	return 0;
}
