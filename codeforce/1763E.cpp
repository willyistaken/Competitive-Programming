#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	vector<pair<int,int> > dp(n+1);			
	dp[0]={0,0};
	for(int i=1;i<=n;i++){
		ll mins = 1e18;
		int pos = -1;
		for(int s=2;i-(1LL*s*(s-1)/2)>=0;s++){
			if(mins>dp[i-(1LL*s*(s-1))/2].first+s){
				mins = dp[i-(1LL*s*(s-1))/2].first+s;
				pos = s;
			}
		}
		dp[i] = {mins,pos};
	}
	vector<int> ans;
	int cur = n;
	while(cur){
		int s = dp[cur].second;
		ans.push_back(s);
		cur-= (1LL*s*(s-1))/2;
	}
	sort(ans.begin(),ans.end(),greater<int>());
	ll sum = 0;
	ll asum = 0;
	for(auto i : ans){
		asum+=i*sum;
		sum+=i;
	}
	cout<<sum<<" "<<asum<<"\n";
	return 0;
}
