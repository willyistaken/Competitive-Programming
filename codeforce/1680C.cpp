#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

void solve(){
	string s;cin>>s;
	int n=  s.size();
	s = " "+s;
	int a[n+1];
	int b[n+2];
	int ap[n+1];
	a[0]=0;
	b[n+1]=0;
	ap[0]=0;
	for(int i=1;i<=n;i++){
		a[i] = a[i-1]+(s[i]=='0');
		ap[i] = ap[i-1]+(s[i]=='1');
	}
	for(int i=n;i>=1;i--){
		b[i] = b[i+1]+(s[i]=='1');
	}
	int ans = 1e9;
	for(int i=1;i<=n;i++){
		int l = i-1;
		int r = n+1;
		while(r-l>1){
			int m =  (l+r)/2;
			if(ap[i-1]+b[m+1]>=a[m]-a[i-1])  l = m;
			else r = m;
		}
		if(l>=i) ans = min(ans,max(ap[i-1]+b[l+1],a[l]-a[i-1]));
		if(r<=n) ans = min(ans,max(ap[i-1]+b[r+1],a[r]-a[i-1]));
	}
	cout<<min(ans,max(0,ap[n]))<<"\n";
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
