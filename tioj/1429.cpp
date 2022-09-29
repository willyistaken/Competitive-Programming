#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::
int n,m;
vector<vector<int> > side;
vector<int> c;
vector<int> l;
vector<int> subsize;
ll ans=0;
int sizeinit(int u){
	int sz=1;
	for(auto i : side[u]){
		sz+=sizeinit(i);	
	}
	subsize[u]=sz;
	return sz;
}

ll dfs(int u,priority_queue<int> &pq){
	ll sum=0;
	int maxsub=-1;int maxsubsz=0;
	for(auto i : side[u]){
		if(subsize[i]>maxsubsz){
			maxsub = i;
			maxsubsz = subsize[i];
		}
	}
	if(maxsub!=-1) sum = dfs(maxsub,pq);
	priority_queue<int> temp;
	for(auto i : side[u]){
		if(i==maxsub) continue;
		sum+=dfs(i,temp);
		while(temp.size()){
			pq.push(temp.top());temp.pop();	
		}
	}
	pq.push(c[u]);
	sum+=c[u];
	while(pq.size() && sum>m){
		sum-=pq.top();
		pq.pop();
	}
	ans = max(ans,1LL*l[u]*(ll)pq.size());
	return sum;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	side.resize(n+1);
	c.resize(n+1,0);
	l.resize(n+1,0);
	subsize.resize(n+1,0);
	for(int i=1;i<=n;i++){
		int b;cin>>b>>c[i]>>l[i];
		side[b].push_back(i);
	}

	sizeinit(1);
	priority_queue<int> my;
	dfs(1,my);
	cout<<ans<<"\n";
	return 0;
}
