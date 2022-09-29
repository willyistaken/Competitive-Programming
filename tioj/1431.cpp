#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::
__int128 f[26];
ll ans(string s){
	int cnt[26] = {0};
	for(auto i : s) cnt[i-'a']++;
	if(s.size()%2){
		int oddcnt=0;
		for(int i=0;i<26;i++){
			if(cnt[i] & 1) oddcnt++;
		}
		if(oddcnt!=1){
			return 0;
		}
		for(int i=0;i<26;i++){
			if(cnt[i] & 1) cnt[i]--;
			cnt[i]>>=1;
		}
		int total = s.size()-1;
		total>>=1;
		__int128 r = f[total];
		for(int i=0;i<26;i++){
			r/=f[cnt[i]];
		}
		return (ll)r;
	}else{
		for(int i=0;i<26;i++){
			if(cnt[i] & 1){
				return 0;
			}else{
				cnt[i]>>=1;
			}
		}
		int total = s.size()/2;
		__int128 r= f[total];
		for(int i=0;i<26;i++){
			r/=f[cnt[i]];
		}
		return (ll)r;
	}
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	f[0]=1;f[1]=1;
	for(ll i=2;i<26;i++) f[i]=f[i-1]*i;
	int t;cin>>t;
	while(t--){
		string s;cin>>s;
		cout<<ans(s)<<"\n";
	}
	return 0;
}
