#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
#define int ll
const int N = 2505;
ll dp[N][N]; string s;
int a,b,c;
int h[N][N];
const int MOD = 712271227;
const int P = 101;
int hsh[N];
int ppow[N];
int get(int l,int r){
	ll ans = hsh[r];
	ans = (ans-(1LL*hsh[l-1]*ppow[r-l+1])%MOD)%MOD;
	if(ans<0) ans+=MOD;
	return ans;
}
signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	cin>>s;
	cin>>a>>b>>c;	
	ppow[0]=1;
	for(int i=1;i<=n;i++){
		hsh[i] = (1LL*hsh[i-1]*P)%MOD;
		hsh[i]+=(s[i-1]-'a');
		hsh[i]%=MOD;
		ppow[i] = (1LL*P*ppow[i-1])%MOD;
	}

	for(int len=1;len<=n;len++){
		vector<pair<int,int> > hsharr;
		for(int i=1;i+len-1<=n;i++){
			hsharr.push_back({get(i,i+len-1),i});
		}
		sort(hsharr.begin(),hsharr.end());
		int k = hsharr.size();
		int l = 0;int r = 0;
		int head = 0;
		for(;l<k;l++){
			while(r<k && hsharr[r].first==hsharr[l].first) r++;
			while(head<r && hsharr[head].second<=hsharr[l].second+len-1) head++;
			if(head<r) h[hsharr[l].second][len]=hsharr[head].second;
		}
	}
	/*for(int l=1;l<=n;l++){
		for(int i=1;i<=n;i++){
			cout<<h[i][l]<<" ";
		}
		cout<<"\n";
	}*/
	for(int i=0;i<=n;i++){
		for(int j=i;j<=n;j++){
			dp[i][j] = 1LL*(j-i+1)*a+b;
		}
	}
	for(int l=1;l<n;l++){
	//	cout<<l<<":";
		for(int i=1;i+l-1<=n;i++){
			int j = i+l-1;
			dp[i-1][j] = min(dp[i][j]+a,dp[i-1][j]);
			dp[i][j+1] = min(dp[i][j]+a,dp[i][j+1]);
			int cnt =2;
			int k = h[i][l];
			for(;k+l-1<=n && k>0 ;k=h[k][l]){
				dp[i][k+l-1] = min(dp[i][k+l-1],dp[i][i+l-1]+1LL*c*cnt+1LL*a*((k+l-i)-(cnt*l))+b);
				cnt++;
			}
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++) cout<<dp[i][j]<<" ";
		cout<<"\n";
	}*/
	//cout<<n<<"\n";
	//cout<<s<<"\n";
	cout<<dp[1][n]-b<<"\n";
	return 0;
}

/*
18
aababbbababbbaabbb
100
1
10
 

806020000
*/
