#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::

vector<int> hshf;
vector<int> hshb;
const int p = 97;
const int MOD = 1e9+7;
int n;

int ppow(int g){
	int r=1;
	int a = p;
	while(g){
		if(g & 1) r = (1LL*a*r)%MOD;
		a = (1LL*a*a)%MOD;
		g>>=1;
	}
	return r;
}

int getnbackf(int k){
	int fr =  (hshf[n]-(1LL*ppow(n-k)*hshf[k])%MOD)%MOD;
	if(fr<0) fr+=MOD;
	int ans = ((1LL*fr*ppow(k))%MOD + hshf[k])%MOD;
	return ans;
}

int getnbackb(int k){
	k = n-k;
	int fr = (hshb[n] - (1LL*ppow(n-k)*hshb[k])%MOD)%MOD;
	if(fr<0) fr+=MOD;
	int ans = ((1LL*fr*ppow(k))%MOD + hshb[k])%MOD;
	return ans;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;cin>>s;
	n = s.size();
	hshf.resize(n+1,0);
	hshb.resize(n+1,0);
	for(int i=1;i<=n;i++){
		hshf[i] = (((1LL*hshf[i-1]*p)%MOD) + s[i-1])%MOD;
	}
	for(int i=1;i<=n;i++){
		hshb[i] = (((1LL*hshb[i-1]*p)%MOD)+ s[n-i])%MOD;
	}
	vector<int> A;
	for(int i=0;i<n;i++){
		if(getnbackf(i)==getnbackb(i))  A.push_back(i);
	}
	if(A.size()){
		cout<<A.size()<<":";
		for(auto i : A) cout<<" "<<i;
		cout<<"\n";
	}else{
		cout<<"none\n";
	}
	return 0;
}
