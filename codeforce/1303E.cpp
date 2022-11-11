#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
string s;
string t;

bool check(int p) {
//	cout<<p<<":\n";
    int dp[p+1];
    for(int j = 0; j<p+1; j++) {
        dp[j] = -1e9;
    }
    dp[0] = 0;
    for(int i=1; i<=s.size(); i++) {
		for(int j=p;j>=0;j--){
			if(dp[j]>=0 && s[i-1]==t[p+dp[j]]){
				dp[j]+=1;
			}
			if( j && s[i-1]==t[j-1]){
				dp[j] = max(dp[j],dp[j-1]);
			}
			//cout<<dp[j]<<" ";
		}
		//cout<<"\n";
    }
	return dp[p]==t.size()-p;		
}

void solve() {
    cin>>s>>t;
	if(s.size()==1){
		if(t[0]==s[0]) cout<<"YES\n";
		else cout<<"NO\n";
		return ;
	}
    for(int i=1; i<s.size(); i++) {
        if(check(i)) {
            cout<<"YES\n";
			return ;
        }
    }
    cout<<"NO\n";
}




int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}
