#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 5005;
ll dp[N];
int Bpa[N];
	
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,K;cin>>n>>K;			
	string s;cin>>s;
	int pa = 0;
	int pb = 0;
	for(int i=1;i<=2*n;i++){
		if(s[i-1]=='A') pa++;
		if(s[i-1]=='B') Bpa[++pb]=pa;
	}
	for(int i=1;i<=n;i++) dp[i]=1e15;
	int best = 0;
	for(int k=1;k<=K;k++){
		for(int i=n;i>=1;i--){
			dp[i] = 1e18;
			int cost = 0;
			for(int j=1;j<=i;j++){
				cost+=max(0,i-Bpa[i-j+1]);
				if(dp[i]>cost+dp[i-j]) best=i-j;
				dp[i] = min(dp[i],cost+dp[i-j]);
			}
			cout<<dp[i]<<","<<best<<" ";
		}
		cout<<"\n";
	}
	cout<<dp[n]<<"\n";
	return 0;
}
