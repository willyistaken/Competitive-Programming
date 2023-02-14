#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

void solve(){
	int n;cin>>n;
	int q;cin>>q;
	ll s[n+1];
	int x[n+1];
	s[0]=x[0]=0;
	for(int i=1;i<=n;i++){
		int a;cin>>a;
		s[i]=s[i-1]+a;
		x[i]=x[i-1]^a;
	}
	cin>>q>>q;
	ll tar = s[n]-s[0]-(x[n]^x[0]);
	int po = 0;
	pair<int,int> cans = {1,n};
	for(int i=1;i<=n;i++){
		if(s[i]-s[po]-(x[i]^x[po])<tar) continue;
		while(s[i]-s[po]-(x[i]^x[po])==tar && po<i) po++;	
		if(cans.second-cans.first+1>i-po+1){
			cans = {po,i};
		}
		po--;
	}
	cout<<cans.first<<" "<<cans.second<<"\n";
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
