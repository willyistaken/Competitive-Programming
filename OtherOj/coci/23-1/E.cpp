#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N = 1e5+5;
int p[N];
int low[N];
int dep[N];
int t;
int mob[N];
int mos[N];
bool isc[N];
pair<int,int> moc[N];
vector<int> side[N];
void dfs(int cur){
	dep[cur]=low[cur]=++t;
	moc[cur]={1e9,1e9};
	int cnt = 0;
	for(auto i : side[cur])	{
		if(i==p[cur]) continue;
		if(dep[i])	low[cur]=min(low[cur],dep[i]);
		else{
			cnt++;
			p[i]=cur;
			dfs(i);
			low[cur]=min(low[cur],low[i]);
			if(low[i]<=moc[i].first){
				moc[i].second = moc[i].first;
				moc[i].first=low[i];
			}else if(low[i]<=moc[i].second){
				moc[i].second = low[i];
			}
			if(cur!=1 && low[i]>=dep[cur]){
				isc[cur]=1;
			}
		}
	}
	if(cur==1 && cnt>1){
		isc[cur]=1;
	}
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;		
	vector<pair<int,int> > edges;
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
		edges.push_back({a,b});
	}
	dfs(1);
	for(int i=2;i<=n;i++){
		mob[i]=mos[i]=dep[i];
		int v = p[i];
		if(moc[v].first==low[i]){
			mob[i]	= min(mob[i],moc[v].second);
		}else{
			mob[i]  = min(mob[i],moc[v].first);
		}
		for(auto e : side[e]){
			mos[i] = min(mos[i],dep[e]);
		}
	}
	int cnt = 0;	
	for(auto temp : edges){
		int a = temp.first;
		int b = temp.second;
		if(dep[a]>dep[b]) swap(a,b);
		if(isc[a] || isc[b]) continue;
		
	}
	return 0;
}
