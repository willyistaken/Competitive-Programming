#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N = 3005;
ll s[N][2];
ll sum[N];
ll dp[N];
ll temp[N];
int n,k;
ll cost(int i,int j){
	int m = (i+j)/2;
	ll ans  = s[m][0]-s[i-1][0]-(1LL*(i)*(sum[m]-sum[i-1]));
	ans+= (s[j][1]-s[m][1])-(1LL*(n-j+1)*(sum[j]-sum[m]));
	return ans;
}

void solve(int l,int r,int tl,int tr){
	if(l>r) return ;
	int m = (l+r)/2;
	dp[m] = temp[tl]+cost(tl,m);
	int pos = tl;
	for(int i=tl+1;i<=min(tr,m-1);i++){
		if(dp[m]>temp[i]+cost(i,m)){
			dp[m] = temp[i]+cost(i,m);
			pos = i;
		}
	}
	solve(l,m-1,tl,pos);
	solve(m+1,r,pos,tr);
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;	
	for(int i=1;i<=n;i++){
		int c;
		cin>>c;
		sum[i]=c+sum[i-1];
		s[i][0] = s[i-1][0]+1LL*i*c;
		s[i][1] = s[i-1][1]+1LL*(n-i+1)*c;
	}
	for(int i=1;i<=n;i++){
		temp[i] = s[i][1] - ((n-i+1)*sum[i]);
	}
	for(int i=2;i<=k;i++){
		for(int j=1;j<=i;j++) dp[j] = 0; 
		solve(i+1,n,1,n);	
		for(int i=1;i<=n;i++) temp[i] = dp[i];
	}
	ll ans = 1e18;
	for(int i = k;i<=n;i++){
		ans = min(ans,dp[i]+(s[n][0]-s[i-1][0])-1LL*i*(sum[n]-sum[i-1]));
	}
	cout<<ans<<"\n";
	return 0;
}
