
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::

const int MOD = 1e9+7;

inline int m(int k){
	k%=MOD;
	if(k<0) k+=MOD;
	return k;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int dp[n]={0};
	int ans = 1;
	int a;cin>>a;dp[--a]=1;
	for(int i=1;i<n;i++){
		cin>>a;
		a--;
		int temp = m(ans-dp[a]);
		dp[a] = ans;
		ans  = m(ans+temp);
	}
	cout<<ans<<"\n";

	return 0;
}
