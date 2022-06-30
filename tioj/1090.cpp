#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,l;
ll dp[1005][1005][2]={{{0}}};
vector<int> p;
ll DP(int i,int j,bool e){
	if(i<0 || j>n) return 1e15;
	if(i==j && p[i]==l) return 0;
	if(p[i]>l || p[j]<l ) return 1e15;
	if(i>j) return 1e15;
	if(dp[i][j][e])	return dp[i][j][e];
	ll ans = LONG_LONG_MAX;
	if(e){
		ans = min( DP(i,j-1,1) + (1LL*(p[j]-p[j-1])*(n-j+i+1)) , DP(i,j-1,0) + (1LL*(p[j]-p[i])*(n-j+i+1)) );	
	}else{
		ans = min( DP(i+1,j,0) + (1LL*(p[i+1]-p[i])*(n-j+i+1)) , DP(i+1,j,1) + (1LL*(p[j]-p[i])*(n-j+i+1)) );
	}
	dp[i][j][e]=ans;
	return dp[i][j][e];
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>l;
	p.resize(n+1);
	for(int i=0;i<n;i++) cin>>p[i];
	p[n]=l;
	sort(p.begin(),p.end());
	cout<<min( DP(0,n,0),DP(0,n,1) );	


	return 0;
}
