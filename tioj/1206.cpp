#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::

const int MOD = 1e9+7;
const int p = 137;


vector<int> hsh;
vector<int> ppow;
int n;
string s;
int getrange(int l,int r){
	int rhsh = hsh[r];
	int lhsh = hsh[l];
	lhsh = (1LL*lhsh*ppow[r-l])%MOD;
	rhsh = (rhsh - lhsh)%MOD;
	if(rhsh<0) rhsh+=MOD;
	return rhsh;	
}

void hshinit(){
	ppow[0]=1;
	for(int i=1;i<=n;i++){
		hsh[i] = ((1LL*hsh[i-1]*p)%MOD+(s[i-1]-'0'))%MOD;
		ppow[i] = (1LL*ppow[i-1]*p)%MOD;
	}
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	while(cin>>s){
		n = s.size();	
		hsh.resize(n+1);
		ppow.resize(n+1);
		fill(hsh.begin(),hsh.end(),0);
		fill(ppow.begin(),ppow.end(),0);
		hshinit();
		for(int i=n/2;i>=0;i--){
			int back = getrange(n-i,n);
			int moreback = getrange(n-2*i,n-i);
			if(back==moreback){
				cout<<i<<"\n";
				break;
			}
		}
	}

	return 0;
}
