#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::
#include <unistd.h>
inline char RC(){static char buf[65536],*p=buf,*q=buf;return p==q&&(q=(p=buf)+read(0,buf,65536))==buf?-1:*p++;}
inline int R(){
	int ans = 0; char c = RC(); bool minus = false;
	while((c < '0' or c > '9') and c != '-' and c != EOF) c = RC();
	if(c == '-') minus = true, c = RC();
	while(c >= '0' and c <= '9') ans = ans * 10 + (c ^ '0'), c = RC();
	return minus ? -ans : ans;
}



// dp[i][0]  = max(dp[i-1][0],si-min(sj) );
// dp[i][1] = max(dp[i-1][1],max(si-sk + dp[k-1][0]),max(si-sk+dp[k][1])));
ll dp[1000005][3];
int main(){
	int n = R();
	ll minf = -1e17;
	for(int i=0;i<1000005;i++){
		dp[i][0] = minf;
		dp[i][1] = minf;
		dp[i][2] = minf;
	}
	ll ans = minf;
	ll nowmax = minf;
	for(int i=2;i<=n+1;i++){
		int a = R();
		dp[i][0] = max(dp[i-1][0],0LL)+a;
		dp[i][1] = max(dp[i-1][1],dp[i-1][2])+a;
		dp[i][2] = max({dp[i-1][2],dp[i-1][0],dp[i-1][1]});
		ans = max(dp[i][1],ans);
	}
	printf("%lld\n",ans);
	return 0;
}
