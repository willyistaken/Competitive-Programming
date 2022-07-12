#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	ll h[n+1]={0};
	for(int i=1;i<=n;i++){
		cin>>h[i];
		h[i]=h[i]^h[i-1];
	}
	while(q--){
		int l,r;cin>>l>>r;
		l--;
		cout<<(h[r]^h[l])<<"\n";
	}
	return 0;
}
