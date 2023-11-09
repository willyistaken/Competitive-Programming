#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 2e5+5;
vector<int> side[N];
bool pos[N];
int p[N][20];
pair<int,int> dep[N];
int t= 0;
void dfs(int cur,int pa=0){
	dep[cur].first=++t;
	for(auto i : side[cur])	{
		if(i!=pa){
			p[i][0]=cur;
			dfs(i,cur);
		}
	}
	dep[cur].second=++t;
}

int llca(int a,int b){
	if(dep[a].first<dep[b].first && dep[a].second>dep[b].second){
		for(int f=19;f>=0;f--){
			if(dep[a].first<dep[p[b][f]].first && dep[a].second>dep[p[b][f]].second) b = p[b][f];
		}
		return b;
	}
	return p[a][0];
}

void mark(int cur,int k){
	if(pos[cur]) return;
	pos[cur]=1;
	for(auto i : side[cur]){
		if(i!=k){
			mark(i,k);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;	
	for(int i=0;i<n-1;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
	}
	dfs(1);
	for(int i=0;i<20;i++) p[1][i]=1;
	for(int f=1;f<20;f++){
		for(int i=2;i<=n;i++){
			p[i][f] = p[p[i][f-1]][f-1];
		}
	}
	int q;cin>>q;
	while(q--){
		int a,b;cin>>a>>b;	
		int c = llca(a,b);
		mark(c,a);
	}
	int cnt=0;
	for(int i=1;i<=n;i++) if(!pos[i]) cnt++;
	cout<<cnt<<"\n";
	for(int i=1;i<=n;i++) if(!pos[i]) cout<<i<<" ";
	cout<<"\n";
	return 0;
}
