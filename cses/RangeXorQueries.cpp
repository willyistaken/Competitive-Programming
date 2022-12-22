#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	int xorsum[n+1]={0};
	for(int i=1;i<=n;i++){
		cin>>xorsum[i];
		xorsum[i]^=xorsum[i-1];
	}
	while(q--){
		int a,b;cin>>a>>b;
		a--;cout<<(xorsum[b]^xorsum[a])<<"\n";
	}

	return 0;
}

