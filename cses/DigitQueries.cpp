#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

void solve(){
	ll k;cin>>k;
	ll d = 9;
	ll stuff = 0 ;
	int cnt= 1;
	while(k>(cnt)*d){
		cnt++;
		k-=(cnt-1)*d;
		d*=10;
		stuff  = stuff*10 + 9;
	}
	//cerr<<k<<"\n";
	//cout<<cnt<<"\n";
	stuff+=(k/cnt)-(k%cnt==0)+1;
	//cout<<stuff<<"\n";
	int g = k%cnt;
	if(g==0) g = cnt;
	for(int i=0;i<cnt-g;i++){
		stuff/=10;
	}
	cout<<stuff%10<<"\n";
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int q;cin>>q;
	while(q--) solve();

	return 0;
}
