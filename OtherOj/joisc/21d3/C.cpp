#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N = 2e5+5;
vector<int> side[N];
int sz[N];
int dep[N];
int P[N][20];
void dfs(int cur,int p){
	sz[cur]=1;
	for(auto i : side[cur]){
		if(i!=p){
			dfs(i,cur);
			sz[cur]+=sz[i];
		}
	}
}

void built(int cur,int p){
	P[cur][0]=p;
	for(auto i : side[cur])	{
		if(i!=p){
			dep[i] = dep[cur]+1;
			built(i,cur);
		}
	}
}

int n;
int centroid(int cur,int p){
	for(auto i : side[cur]){
		if(i==p) continue;
		if(sz[i]>n/2) return centroid(i,cur);
	}
	return cur;
}

int dis(int a,int b){
	if(dep[a]>dep[b]) swap(a,b);
	int oga = a;
	int ogb = b;
	if(dep[a]!=dep[b]){
		for(int i=19;i>=0;i--){
			if(dep[P[b][i]]>dep[a]) b = P[b][i];
		}
		b = P[b][0];
	}
	assert(dep[a]==dep[b]);
	int c = 0;
	if(a==b) c = a;
	else{
		for(int i=19;i>=0;i--){
			if(P[a][i]!=P[b][i]) {
				a = P[a][i];
				b = P[b][i];
			}
		}
		c = P[a][0];
	}
	return dep[oga]+dep[ogb]-2*dep[c]+1;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=0;i<n-1;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
	}
	dfs(1,0);
	int cen = centroid(1,0);
	dfs(cen,0);
	vector<int> ord;	
	for(int i=1;i<=n;i++) ord.push_back(i);
	sort(ord.begin(),ord.end(),[&](const int &a,const int &b){return sz[a]>sz[b];});
	built(cen,0);	
	P[cen][0]=cen;
	for(int j=1;j<20;j++){
		for(int i=1;i<=n;i++) P[i][j] = P[P[i][j-1]][j-1];
	}
	vector<int> ans(n+1,0);
	int dia = 1;
	int one = cen;
	int two = -1;
	int head = 1;
	for(int i=(n/2+1);i>=0;i--){
		while(head<n && sz[ord[head]]>=i){
			int a = ord[head];
			if(two==-1){
				two = a;
				dia = max(dia,dis(a,one));
			}else{
				int dis1 = dis(a,one);
				int dis2 = dis(a,two);
				if(dis1>dia){
					two = a;
					dia= dis1;
				}else if(dis2>dia){
					one = a;
					dia = dis2;
				}
			}
			head++;
		}
		ans[i] = dia;
	}
	for(int i=1;i<=n;i++){
		if(i&1)	 cout<<1<<"\n";
		else cout<<ans[i/2]<<"\n";
	}
	return 0;
}
