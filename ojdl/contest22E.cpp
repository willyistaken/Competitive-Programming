#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int MOD = 1e9+7;
const int p = 71;
int hsh[2005];
int ppow[2005];


int get(int l,int r){
	ll ans = hsh[r];
	ans = (ans-(1LL*hsh[l-1]*ppow[r-l+1])%MOD)%MOD;
	if(ans<0) ans+=MOD;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;cin>>s;	
	int n = s.size();
	ppow[0]=1;
	for(int i=0;i<s.size();i++){
		hsh[i+1] = (1LL*hsh[i]*p)%MOD +(s[i]-'a');
		hsh[i+1]%=MOD;
		ppow[i+1] = (1LL*ppow[i]*p)%MOD;
	}
	vector<pair<int,int> > ans;
	for(int len=3;len<=n;len+=3){
		int k = len/3;	
		for(int i=1;i+len-1<=n;i++){
			int f = get(i,i+k-1);	
			int s = get(i+k,i+k+k-1);
			int t =	get(i+k+k,i+k+k+k-1);	
			if(f!=s && s==t) ans.push_back({i,i+len-1});
		}
	}
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<"\n";
	for(int i=0;i<ans.size();i++){
		cout<<ans[i].first<<" "<<ans[i].second;
		if(i!=ans.size()-1) cout<<"\n";
	}
	return 0;
}
