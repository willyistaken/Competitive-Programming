#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct edge{
	int to;
	int c;
	int p;
};

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,a,b,d;cin>>n>>m>>a>>b>>d;
	vector<vector<edge > > side(n+1);
	for(int i=0;i<m;i++){
		int a,b,c1,p1,c2,p2;cin>>a>>b>>c1>>p1>>c2>>p2;
		side[a].push_back({b,c1,p1});
		side[b].push_back({a,c2,p2});
	}
	ll dp[n+1];
	fill(dp,dp+n+1,1e16);
	dp[a]=0;
	queue<int> tob;
	tob.push(a);
	while(!tob.empty()){
		int ft = tob.front();
		tob.pop();
		for(auto i : side[ft]){
			if(dp[i.to]>dp[ft]+i.c){
				dp[i.to]=dp[ft]+i.c;
				tob.push(i.to);
			}
		}
	}
	ll disab0 = dp[b];
	fill(dp,dp+n+1,1e16);
	dp[b]=0;
	tob.push(b);
	while(!tob.empty()){
		int ft = tob.front();
		tob.pop();
		for(auto i : side[ft]){
			if(dp[i.to]>dp[ft]+i.c){
				dp[i.to]=dp[ft]+i.c;
				tob.push(i.to);
			}
		}
	}
	ll disba0 = dp[a];
	
	fill(dp,dp+n+1,1e16);
	dp[a]=0;
	tob.push(a);
	while(!tob.empty()){
		int ft = tob.front();
		tob.pop();
		for(auto i : side[ft]){
			if(dp[i.to]>dp[ft]+i.c+(1LL*(d-1)*i.p)){
				dp[i.to]=dp[ft]+i.c+(1LL*(d-1)*i.p);
				tob.push(i.to);
			}
		}
	}
	ll disabd = dp[b];
	fill(dp,dp+n+1,1e16);
	dp[b]=0;
	tob.push(b);
	while(!tob.empty()){
		int ft = tob.front();
		tob.pop();
		for(auto i : side[ft]){
			if(dp[i.to]>dp[ft]+i.c+(1LL*(d-1)*i.p)){
				dp[i.to]=dp[ft]+i.c+(1LL*(d-1)*i.p);
				tob.push(i.to);
			}
		}
	}
	ll disbad = dp[a];
	cout<<min(disab0+disba0,disabd+disbad)<<"\n";







	return 0;
}
