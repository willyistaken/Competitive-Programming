#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

#define int ll
const int MOD = 1e9+7;

int hsh(string &s,int l,int r){
	int p = 31;
	int ans=  0;
	for(int i=l;i<r;i++){
		ans=(1LL*ans*p)%MOD;
		ans+=(s[i]-'A');
		ans%=MOD;
	}
	return ans;
}

bool thesame(string s){
	char a = s[0];
	for(auto i : s){
		if(i!=a) return 0;
	}
	return 1;
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k;cin>>n>>k;		
	int cnt[26];
	vector<vector<string> > arr(n+1);
	for(int i=1;i<=n;i++){
		for(int j=0;j<k;j++){
			string a;cin>>a;
			arr[i].push_back(a);
		}
	}
	int dp[k] = {0};
	for(int i=0;i<k;i++) dp[i]=1;
	map<int,int> mp;
	for(int i=n;i>=1;i--){
		if(i!=n){
			for(int j=0;j<k;j++){
				int whole = hsh(arr[i][j],0,i);
				dp[j] = mp[whole];
				if(thesame(arr[i][j])){
					dp[j]-=cnt[arr[i][j][0]-'a'];
				}
				dp[j]%=MOD;
			}
		}
		mp.clear();
		for(int i=0;i<26;i++) cnt[i]=0;
		for(int j=0;j<k;j++){
			if(thesame(arr[i][j])){
				cnt[arr[i][j][0]-'a']+=dp[j];
				cnt[arr[i][j][0]-'a']%=MOD;
			}
			int left = hsh(arr[i][j],0,i-1);
			int right = hsh(arr[i][j],1,i);
			mp[left]+=dp[j];
			mp[right]+=dp[j];
			mp[left]%=MOD;
			mp[right]%=MOD;
		}
	}
	int ans = 0;
	for(int i=0;i<k;i++){
		ans+=dp[i];
		ans%=MOD;
	}
	if(ans<0) ans+=MOD;
	cout<<ans<<"\n";
	return 0;
}
