#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100;
ll dp[N];
int main(){
	dp[0]	=1;
	dp[1]=1;
	int n;cin>>n;
	for(int i=2;i<=n;i++){
		dp[i] = dp[i-1]+dp[i-2];
	}
	cout<<dp[n]<<"\n";
}
