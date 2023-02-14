#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
int n,k;
string s;
bool dp[355][355][355];
bool vis[355][355][355];
int rs[355];
bool DP(int l,int r,int g){
	if(r<l) {
		assert(1==0);
		return 0;
	}
	if(vis[l][r][g]) return dp[l][r][g];	
	vis[l][r][g]=1;
	if(g==k-1 && s[l]=='C' && s[r]=='C'){
		dp[l][r][g] = 0;
		return dp[l][r][g];
	}
	int other = rs[l-1]+rs[n]-rs[r]-g;
	if(g==k-1 && s[l]=='C'){
		dp[l][r][g] = !DP(l,r-1,other);
		return dp[l][r][g];
	}
	if(g==k-1 && s[r]=='C'){
		dp[l][r][g] = !DP(l+1,r,other);
		return dp[l][r][g];
	}
	if(DP(l+1,r,other) && DP(l,r-1,other)){
		dp[l][r][g] = 0;
		return dp[l][r][g];
	}else{
		dp[l][r][g]=1;
		return dp[l][r][g];
	}
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;		
	cin>>s;
	s = " "+s;
	for(int i=1;i<=n;i++){
		rs[i] =rs[i-1]+(s[i]=='C');
	}
	if(DP(1,n,0)) cout<<"DA\n";
	else cout<<"NE\n";
	return 0;
}
