#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

int n,a,b,c,d;
pair<ll,ll> dp[3005][3005];
ll arr[3005];
ll sum[3005];
pair<ll,ll> cost(int l,int r,ll v){
	return make_pair(-dp[l][r].second+v,-dp[l][r].first);
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>a>>b>>c>>d;
	for(int i=1;i<=n;i++) cin>>arr[i];
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+arr[i];
	for(int l=1;l<=n;l++){
		deque<int> costa;
		deque<int> costc;
		int heada = 1;
		int headc = 1;	
		for(int i=1;i<=n;i++){
			if(i+l-1>n) continue;
			if(l==1){
				dp[i][i+l-1] = {arr[i],0};
			}else{
				dp[i][i+l-1] = max(cost(i+1,i+l-1,arr[i]),cost(i,i+l-2,arr[i+l-1]));
				if(l<b){
					dp[i][i+l-1] = max(dp[i][i+l-1],{sum[i+l-1]-sum[i-1]-a,0});
				}else{
					while(costa.size()){
						if(costa[0]<i) costa.pop_front();
						else break;
					}
					while(heada<i+l-b+1 && heada+b-1<=n){
						int g = 0;
						while(( g = costa.size()) && g){
							int j = costa[g-1];
							if(cost(j,j+b-1,-(sum[j+b-1]-sum[j-1]+a))<=cost(heada,heada+b-1,-(sum[heada+b-1]-sum[heada-1]+a))) costa.pop_back();
							else break;
						}
						costa.push_back(heada);
						heada++;
					}
				}

				if(l<d){
					dp[i][i+l-1] = max(dp[i][i+l-1],{sum[i+l-1]-sum[i-1]-c,0});
				}else{
					while(costc.size()){
						if(costc[0]<i) costc.pop_front();
						else break;
					}
					while(headc<i+l-d+1 && headc+d-1<=n){
						int g = 0;
						while((g = costc.size()) && g){
							int j = costc[g-1];
							if(cost(j,j+d-1,-(sum[j+d-1]-sum[j-1]+c))<=cost(headc,headc+d-1,-(sum[headc+d-1]-sum[headc-1]+c))) costc.pop_back();
							else break;
						}
						costc.push_back(headc);
						headc++;
					}
				}
				if(costa.size()){
					int j = costa[0];
					dp[i][i+l-1] = max(dp[i][i+l-1],cost(j,j+b-1,sum[i+l-1]-sum[i-1]-(sum[j+b-1]-sum[j-1]+a)));
				}
				if(costc.size()){
					int j = costc[0];
					dp[i][i+l-1] = max(dp[i][i+l-1],cost(j,j+d-1,sum[i+l-1]-sum[i-1]-(sum[j+d-1]-sum[j-1]+c)));
				}
			}
			cout<<dp[i][i+l-1].first<<","<<dp[i][i+l-1].second<<"|";
		}
		cout<<"\n";
	}
	cout<<dp[1][n].first+dp[1][n].second<<"\n";
	return 0;
}
