#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,p;
	while(cin>>n>>p && (n||p) ){
		ll dp[p+1]={0};
		dp[0]=1;int w;
		for(int i=0;i<n;i++){
			cin>>w;
			for(int j=0;j<=p;j++){
				if(j>=w)	dp[j]+=dp[j-w];
			}
		}
		cout<<dp[p]<<"\n";
	}

	return 0;
}
