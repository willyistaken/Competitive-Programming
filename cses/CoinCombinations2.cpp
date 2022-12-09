#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


const int MOD = 1e9+7;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,a;cin>>n>>a;
	int arr[n];
	int dp[a+1] = {0};
	dp[0]=1;
	for(int i=0;i<n;i++){
		int v;cin>>v;
		for(int h = v;h<=a;h++){
			dp[h] = (dp[h]+dp[h-v])%MOD;
		}
	}
	cout<<dp[a]<<"\n";
	return 0;
}

