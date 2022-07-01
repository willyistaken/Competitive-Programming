#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int v,e,mod;cin>>v>>e>>mod;
	int dp[v]={0};
	int ind[v]={0};
	vector<vector<int> > side(v);
	vector<vector<int> > to(v);
	for(int i=0;i<e;i++){
		int a,b;cin>>a>>b;
		side[b].push_back(a);
		to[a].push_back(b);
		ind[b]++;
	}
	vector<int> toposort;
	queue<int> topoqueue;
	for(int i=0;i<v;i++){
		if(ind[i]==0){toposort.push_back(i);topoqueue.push(i);}
	}
	while(!topoqueue.empty()){
		for(auto k : to[topoqueue.front()]){
			ind[k]--;
			if(ind[k]==0){toposort.push_back(k);topoqueue.push(k);}
		}
		topoqueue.pop();
	}
	int s,t;cin>>s>>t;
	bool already=0;
	for(auto i : toposort){
		if(i==s){
			dp[s]=1;
			already=1;
		}else if(already){
			for(auto g : side[i]){
				dp[i]+=dp[g];
				dp[i]%=mod;
			}
		}
		
	}
	cout<<dp[t]<<"\n";
	return 0;
}
