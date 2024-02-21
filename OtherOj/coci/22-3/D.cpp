#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

/*
just get the prime factor and all of its basis, then there is only sigma(n) states, and the biggest of this is... 	240

the complexity is 240*500*500*6;
*/

const int MOD = 998244353;

int dp[300][505][505];
int arr[505][505];
int mp[10000005];
int mul[300][300];




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k;cin>>n>>k;
	vector<int> back;
	for(int i=1;i<=k;i++){
		if(k%i==0){
			back.push_back(i);
			mp[i] = back.size()-1;
		}
	}
	for(int i=0;i<back.size();i++){
		for(int j=0;j<back.size();j++){
			mul[i][j]=mp[__gcd(1LL*back[i]*back[j],1LL*k)];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>arr[i][j];
			if(arr[i][j]==-1) continue;
			arr[i][j] = __gcd(arr[i][j],k);
		}
	}
	dp[mp[arr[1][1]]][1][1]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int f=0;f<(int)(back.size());f++){
				if(arr[i+1][j]>0) {
					int h = mp[arr[i+1][j]];
					dp[ mul[ f ][ h ] ][i+1][j]+=dp[f][i][j];
					if(dp[ mul[ f ][ h ] ][i+1][j]>=MOD) dp[ mul[ f ][ h ] ][i+1][j]-=MOD;
				}
				if(arr[i][j+1]>0) {
					int h = mp[arr[i][j+1]];
					dp[ mul[ f ][ h ] ][i][j+1]+=dp[f][i][j];
					if(dp[ mul[ f ][ h ] ][i][j+1]>=MOD) dp[ mul[ f ][ h ] ][i][j+1]-=MOD;
				}
			}
		}
	}
	cout<<dp[mp[k]][n][n]<<"\n";
	return 0;
}
