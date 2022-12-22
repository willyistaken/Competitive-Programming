#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

int hsh[1000005];
const int p = 17;
const int MOD = 1e9+7;
int po[1000005];

int get(int l,int r){
	int ans = hsh[l-1];
	ans = (1LL*po[(r-l+1)]*ans)%MOD;
	ans = (hsh[r]-ans)%MOD;
	if(ans<0) ans+=MOD;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;cin>>s;	
	for(int i=1;i<=s.size();i++){
		hsh[i] = (1LL*hsh[i-1]*p)%MOD;
		hsh[i] = (hsh[i]+(s[i-1]-'a'))%MOD;
	}
	po[0]=1;
	for(int i=1;i<=s.size();i++){
		po[i] = (1LL*po[i-1]*p)%MOD;
	}
	for(int p=1;p<=s.size();p++){
		int h = get(1,p);
		int l = 1,r = p;
		bool ans = 1;
		while(r<=s.size()){
			if(h!=get(l,r)){
				ans=0;
				break;
			}
			l+=p,r+=p;
		}
		if(!ans) continue;
		int left = s.size()%p;
		if(get(1,left)==get(s.size()-left+1,s.size())){
			cout<<p<<" ";
		}
	}
	cout<<"\n";
	return 0;
}
