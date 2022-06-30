#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll dp[42]={0};
	dp[1]=1;
	dp[3]=4;
	ll sum=1;
	for(int i=5;i<=41;i+=2){
		dp[i]=1+(dp[i-2]*3);
		dp[i]+=sum*2;
		sum+=dp[i-2];
	}
	int n;
	while(cin>>n){
		cout<<dp[n]<<"\n";
	}
	return 0;
}
