#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

ll dp[20][11][2][2];
vector<int> num;
ll DP(int i,int d,bool p,bool z){
	if(i==num.size()) return 1;
	if(dp[i][d][p][z]) return dp[i][d][p][z]; //base case
	int lb = 0;
	int rb = (p)?(num[i]):(9);
	// set upper and lower bound
	ll ans = 0;
	for(int g = lb;g<=rb;g++){
		if(g==d && g!=0) continue;
		if(g==d && g==0 && z==0) continue;
		ans+=DP(i+1,g,p&&(g==num[i]),z&&(g==0));
	}
	// enumerate digit and calculate;
	return (dp[i][d][p][z]=ans);
}

ll count(ll a){
	if(a<0) return 0;
	memset(dp,0,sizeof(dp));
	num.clear();
	while(a){
		num.push_back(a%10);
		a/=10;
	}
	reverse(num.begin(),num.end());
	return DP(0,0,1,1);
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll a,b;cin>>a>>b;
	cout<<count(b)-count(a-1)<<"\n";
	return 0;
}
