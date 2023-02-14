#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

void solve(){
	int cnt;cin>>cnt;
	int ogcnt = cnt;
	int pos = 0;
	int ans = 0;
	for(;pos<35;pos++){
		cout<<"- "<<(1<<pos)<<endl;
		int k;cin>>k;
		int dif = k-cnt;
		cnt = k;
		dif+=1;
		pos+=dif;
		ans+=(1<<pos);
		ogcnt--;
		if(ogcnt==0) break;
	}	
	cout<<"! "<<ans<<endl;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
