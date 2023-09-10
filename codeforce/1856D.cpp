#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
int n;
int ask(int l,int r){
	if(l==r) return 0;
	else{
		cout<<"? "<<l<<" "<<r<<endl;
		int a;cin>>a;
		return a;
	}
}
int maxin(int l,int r){
	if(r==l){
		return r;
	}
	if(r-l==1){
		int a = ask(l,r);
		if(a==1) return l;
		else return r;
	}
	int m = (l+r)/2;
	int lm = maxin(l,m);
	int rm = maxin(m+1,r);
	int base = ask(lm,rm);
	int ano = ask(lm+1,rm);
	if(base-ano==rm-lm) return lm;
	else return rm;
}

void solve(){
	cin>>n;
	int ans = maxin(1,n);
	cout<<"! "<<ans<<endl;
	return;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
