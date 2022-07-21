#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,t[16];
int dp[(1<<16)][16];
int ans(int finish,int g){
	if(dp[finish][g]) return dp[finish][g];
	if(finish==0) return 0;
	assert((finish>>g)&1);
	int mask = finish - (1<<g);
	if(mask==0){
		int arrive = abs(g)+1;
		arrive =  (arrive%t[g])?(arrive+t[g]-(arrive%t[g])):arrive;
		dp[finish][g] = arrive;
		return dp[finish][g];
	}
	int mintime=INT_MAX;
	for(int i=0;i<n;i++){
		if((mask>>i) & 1){
			int arrive = (ans(mask,i) + abs(g-i) );
			arrive =  (arrive%t[g])?(arrive+t[g]-(arrive%t[g])):arrive;
			mintime = min(mintime,arrive);
		}
	}
	dp[finish][g]=mintime;
	return dp[finish][g];
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++) cin>>t[i];
	int minans=INT_MAX;
	int fullmask = (1<<n)-1;
	for(int i=0;i<n;i++){
		minans = min(minans,ans(fullmask,i));	
	}
	cout<<minans<<"\n";
	return 0;
}
