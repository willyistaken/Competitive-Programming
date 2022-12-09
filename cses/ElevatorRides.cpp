#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

int n;
int x;
pair<int,int> cost[(1<<21)];
int w[20];

pair<int,int> Cost(int mask){
	if(mask==0) return {0,1e9};
	if(cost[mask].first!=0) return cost[mask];
	pair<int,int> minn = {1e9,1e9};
	for(int i=0;i<n;i++){
		if(mask & (1<<i)) {
			pair<int,int> temp = Cost(mask-(1<<i));
			if(temp.second+w[i]>x) minn = min(make_pair(temp.first+1,w[i]),minn);
			else minn = min(make_pair(temp.first,temp.second+w[i]),minn);
		}
	}
	cost[mask] = minn;
	return cost[mask];
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	cin>>x;
	for(int i=0;i<n;i++) cin>>w[i];	
	cout<<Cost((1<<(n))-1).first<<"\n";	
	return 0;
}
