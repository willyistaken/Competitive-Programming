/*#include<vector>
#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long ll;
int n,m;
const int MAXN = 1e6+2;
vector<int> child[MAXN];
int groupsize[MAXN];
int dfs(int r){
	if(child[r].size()){
		int maxn=0;
		for(auto i : child[r]){
			maxn = max(maxn,dfs(i));
		}
		groupsize[maxn+1]++;
		return maxn+1;
	}else{
		groupsize[1]++;
		return 1;				
	}
}



int main(){
	scanf("%d %d",&n,&m);	
	for(int i=2;i<=n;i++){
		int f;scanf("%d",&f);
		child[f].push_back(i);
	}
	dfs(1);
	sort(groupsize,groupsize+n+1,greater<int>());
	int ans=0;
	for(int i=0;i<min(n,m); i++){
		ans+=groupsize[i];
	}
	printf("%d\n",ans);
	return 0;
}
*/

/*
greedily take the most of people to a party(take out all the leaf,)
*/
// the first idea is too inefficient...
/*
observation1: the group closer to the bottom of the tree will always be larger than the one at the top
observation2: ai<i (by problem statement) 
we can construct the group number faster by  looping from n to 1 and updating it's parents
and because the lower the better we can decide right away wether we should add it in to the ans (group<m)
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e6+5;
int father[MAXN];
int group[MAXN];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=2;i<=n;i++) cin>>father[i];
	int ans=0;
	for(int i=n;i>=1;i--){
		group[father[i]] = max(group[father[i]],group[i]+1);
		if(group[i]<m) ans++;
	}
	cout<<ans<<"\n";

	return 0;
}
