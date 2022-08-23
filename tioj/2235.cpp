#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::
#include <unistd.h>
inline char RC(){static char buf[65536],*p=buf,*q=buf;return p==q&&(q=(p=buf)+read(0,buf,65536))==buf?-1:*p++;}
inline int R(){static char c;int a;while((c=RC())<'0');a=c^'0';while((c=RC())>='0')a*=10,a+=c^'0';return a;}
int n,m;
vector<vector<int> > side;
vector<int> toposort;

bitset<1000005> hasin;

void dfs(int r){
	hasin[r]=1;
	for(auto i : side[r]){
		if(!hasin[i]) dfs(i);
	}
	toposort.push_back(r);
}

bool hasneighbor(int r,int b){
	for(auto i : side[r]){
		if(i==b) return 1;
	}
	return 0;
}

int main(){
	n = R();m = R();
	side.resize(n+1);
	hasin.reset();
	for(int i=0;i<m;i++){
		int a,b;
		a = R();b=R();
		side[a].push_back(b);
		hasin[b]=1;
	}
	for(int i=1;i<=n;i++) if(!hasin[i]){
		hasin.reset();
		dfs(i);
		break;
	}
	if(toposort.size()!=n){
		puts("-1");
		return 0;
	}
	for(int i=n-1;i>=1;i--){
		if(!hasneighbor(toposort[i],toposort[i-1])){
			puts("-1");
			return 0;
		}
	}
	for(int i=n-1;i>=0;i--){
		printf("%d ",toposort[i]);
	}
	puts("");


	return 0;
}
