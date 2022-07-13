#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
int tspower[105];
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
	string s;
	while(cin>>s){
	int n = s.size();
	int hsh[n]={0};
	for(int i=0;i<n;i++){
		hsh[i] = (((1LL*((i)?hsh[i-1]:0)*26)%MOD) + (s[i]-'A'))%MOD;
	}
	tspower[0]=1;
	for(int i=1;i<105;i++){
		tspower[i] =  (tspower[i-1]*26LL)%MOD;
	}
	for(int i=1;i<=n;i++){
		if(n%i==0){
			int pass=1;
			int nowt = gethash(0,i-1,hsh);
			for(int j=1;j<(n/i);j++){
				if(gethash(i*j,i*(j+1)-1,hsh)!=nowt){
					pass=0;
					break;
				}
			}
			if(pass){
				cout<<(n/i)<<"\n";
				break;
			}
		}	
	}
	}		
	return 0;
}
