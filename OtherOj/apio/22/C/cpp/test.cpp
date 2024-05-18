#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const long long MX = 1e18;
long long count_increasing(const vector<int>& v) {
  vector<long long> dp(v.size() + 1, 0);
  dp[0] = 1;
  for (int x : v)
  {
  	for (int i = 0; i <= x; i++)
  	{
  		dp[x+1] += dp[i];
  		dp[x+1] = min(dp[x+1],MX+1);
  	}
  }
  long long result = 0;
  for (int i = 0; i <= (int)v.size(); i++){
  	result += dp[i];
  	result = min(result,MX+1);
  }
  return result;
}



int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;cin>>n;
	vector<int> a;
	for(int i=0;i<n;i++){
		int h;cin>>h;a.push_back(h);
	}
	cout<<count_increasing(a)<<"\n";

	return 0;
}
