#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k;cin>>n>>k;
	pair<int,int> seq[n];
	for(int i=0;i<n;i++){
		cin>>seq[i].first;
		seq[i].second = i+1;
	}
	int a[n+1][n+1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	sort(seq,seq+n);
	int dp[n+1] = {0};
	for(int j=1;j<=n;j++){
		int maxn = dp[j-1];
		for(int i=j;i<=n;i++){
			int temp = dp[i];
			dp[i] = maxn + a[seq[i-1].second][j];
			maxn = max(maxn,temp);
			if(dp[i]>=k) {
				cout<<j<<"\n";
				return 0;
			}
		}
	}
	cout<<-1<<"\n";
	return 0;
}
