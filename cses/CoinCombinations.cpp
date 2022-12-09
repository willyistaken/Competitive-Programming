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
	for(int i=0;i<n;i++) cin>>arr[i];
	int dp[a+1] = {0};
	dp[0]=1;
	for(int h = 1;h<=a;h++){
		for(int i=0;i<n;i++){
			if(h>=arr[i]) dp[h] = (dp[h]+dp[h-arr[i]])%MOD;
		}
	}
	cout<<dp[a]<<"\n";
	return 0;
}
