#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5000005;
const int MOD = 1e9+7;
int tspower[MAXN];
int gethash(int l,int r,int hsh[]){
	if(l==0) return hsh[r];
	int result = hsh[r];
	int minus = hsh[l-1];
	minus = (1LL*minus*tspower[r-l+1])%MOD;
	result = (result-minus)%MOD;
	if(result<0) result+=MOD;
	return result;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int k;cin>>k;
	string s;cin>>s;
	int n = s.size();
	int hsh[n]={0};
	for(int i=0;i<n;i++){
		hsh[i] = (((1LL*((i)?hsh[i-1]:0)*26)%MOD) + (s[i]-'A'))%MOD;//chose a smaller alphabet
	}
	tspower[0]=1;
	for(int i=1;i<n+5;i++){
		tspower[i] =  (tspower[i-1]*26LL)%MOD;
	}
	int ans=n/k;
	for(;ans>=0;ans--){
		int refrence = gethash(0,ans-1,hsh);
		bool flag=0;
		for(int i=1;i<k;i++){
				if(gethash(i*ans,(i+1)*ans-1,hsh)!=refrence){
					flag=1;
					break;
				}
		}
		if(!flag){
			cout<<ans<<"\n";
			return 0;
		}
	}
	return 0;
}


//hash
