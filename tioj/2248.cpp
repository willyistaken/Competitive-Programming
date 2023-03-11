#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N =  1e5+5;
int dif[N];
int ans[N];
vector<pair<int,int> > side[N];

void dfs(int cur,int p){
	ll ansn = 0;
	for(auto i : side[cur]){
		if(i.first!=p){
			dfs(i.first,cur);
			ansn+=abs(dif[i.first])*i.second+ans[i.first];
			dif[cur]+=dif[i.first];
		}
	}
	ans[cur] =ansn;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k;cin>>n>>k;										
	for(int i=1;i<=n;i++){
		int a;cin>>a;
		dif[i] = k-a;
	}
	for(int i=0;i<n-1;i++){
		int a,b,d;cin>>a>>b>>d;
		side[a].push_back({b,d});
		side[b].push_back({a,d});
	}
	dfs(1,0);
	cout<<ans[1]<<"\n";
	return 0;
}
