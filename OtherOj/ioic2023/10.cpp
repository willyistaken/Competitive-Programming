#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


ll e[4];
const int MOD  = 10007;

ll eval(int x){
	ll s = 0;
	for(int i=0;i<4;i++){
		s = (s*x)%MOD;
		s = (s+e[i])%MOD;
	}
	return s;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(int i=0;i<4;i++) cin>>e[i];
	int cnt = 0;
	for(int i=0;i<MOD;i++){
		if(eval(i)==0) cnt++;
	}
	cout<<cnt<<"\n";
	for(int i=0;i<MOD;i++){
		if(eval(i)==0) cout<<i<<"\n";
	}
	
	return 0;
}
