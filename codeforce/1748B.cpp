#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


int cnt[10];
void solve(){
	int n;cin>>n;
	string s;cin>>s;
	ll sum = 0;
	for(int i=0;i<n;i++){
		for(int g=0;g<10;g++) cnt[g] = 0;
		int dcnt = 0;
		int M = 0;
		for(int j=0;(i+j<n && j<105);j++){
			if(cnt[s[i+j]-'0']==0) dcnt++;
			cnt[s[i+j]-'0']++;	
			M = max(M,cnt[s[i+j]-'0']);
			if(M<=dcnt) sum++;
		}
	}
	cout<<sum<<"\n";

}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--) solve();

	return 0;
}
