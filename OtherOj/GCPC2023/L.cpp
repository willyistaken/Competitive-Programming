#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

int MOD = 1e9+7;
int p = 97;

vector<int> hsh;

int pow(int a,int po){
	ll r = 1;
	while(po){
		if(po&1) r = (a*r)%MOD;
		a = (1LL*a*a)%MOD;
		po>>=1;
	}
	return r;
}


int hs(int l,int r){
	int lhsh=0;
	if(l!=0){
		l--;
		lhsh = hsh[l];
	}
	int rhsh = hsh[r];
	int np = r-l;
	lhsh = (1LL*lhsh*(pow(p,np)))%MOD;
	int k = (rhsh - (lhsh))%MOD;
	if(k<0) k+=MOD;
	return k;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;cin>>s;
	int n = s.size();
	hsh.resize(n,0);
	int cnt = 0;
	for(int i=0;i<n;i++){
		cnt = (1LL*cnt*p)%MOD;
		cnt+=(s[i]=='(');
		hsh[i]= cnt;
	}
	cnt=0;
	vector<int> zeropt;
	for(int i=0;i<n;i++){
		if(s[i]=='(')	cnt++;
		else cnt--;
		if(cnt==0){
			zeropt.push_back(i);
		}
	}
	vector<int> hshg;	
	int prev = 0;
	for(auto i : zeropt){
		hshg.push_back(hs(prev,i))	;
		prev = i+1;
	}
	sort(hshg.begin(),hshg.end());
	if(hshg[0]==hshg[hshg.size()-1]){
		cout<<"no\n";
		return 0;
	}
	int ncnt = 0;			
	for(int i=0;i<n;i++){
		if(s[i]=='(') ncnt++;
		else ncnt--;
		if(ncnt==0){
			for(int j=i+1;j<n;j++)	 cout<<s[j];
			for(int j=0;j<=i;j++)	 cout<<s[j];
			cout<<"\n";
			return 0;
		}
	}
	return 0;
}
