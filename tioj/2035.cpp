#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int power(int _n,int p){
	int ans=1;
	while(p){
		if(p&1) ans*=_n;
		_n = _n*_n;
		p>>=1;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int b;string n;cin>>b>>n;
	int todec=0;
	int selflove=0;
	int d = n.size();
	for(int i=0;i<d;i++){
		todec+=power(b,d-i-1)*(n[i]-'0');
		selflove+=power((n[i]-'0'),d);
	}
	cout<<((todec==selflove) ? "YES\n":"NO\n");
	return 0;
}
