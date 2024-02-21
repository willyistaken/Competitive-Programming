#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N = 3005;

pair<int,int> dp[N][N];
bool v[N][N][2];
bitset<N> exist;
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	vector<int> arr(n+1);
	for(int i=1;i<=n;i++) cin>>arr[i];
	for(int l=1;l<=n;l++){
		exist.reset();
		for(int i=1;i<l;i++){
			exist[arr[i]]=1;
		}
		for(int r=n;r>=l;r--){
			v[l][r][1]=!exist[arr[r]];
			exist[arr[r]]=1;
		}
	}
	for(int r=n;r>=1;r--){
		exist.reset();
		for(int i=n;i>r;i--){
			exist[arr[i]]=1;
		}
		for(int l=1;l<=r;l++){
			v[l][r][0]=!exist[arr[l]];
			exist[arr[l]]=1;
		}
	}
	
	for(int len=1;len<=n;len++)	{
		for(int l=1;l+len-1<=n;l++)	{
			bool k = (n-len)&1;
			if(!k){
				pair<int,int> tl = dp[l+1][l+len-1];
				pair<int,int> tr = dp[l][l+len-2];
				tl.first+=v[l][l+len-1][0];
				tr.first+=v[l][l+len-1][1];
				dp[l][l+len-1] = max(tl,tr);
			}else{
				pair<int,int> tl = dp[l+1][l+len-1];
				pair<int,int> tr = dp[l][l+len-2];
				tl.second+=v[l][l+len-1][0];
				tr.second+=v[l][l+len-1][1];
				dp[l][l+len-1] = min(tl,tr);
			}
		}
	}
	cout<<dp[1][n].first<<":"<<dp[1][n].second<<"\n";

	return 0;
}
