#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int P = 998244353;
int hsh(int x){
    x *= 1664525;
    x ^= x >> 12;
    x ^= x << 25;
    x ^= x >> 27;
    x *= 1103515245;
	x^=x>>16;
	x%=P;
	if(x<0) x+=P;
    return x+1;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k,q;cin>>n>>k>>q;		
	map<int,int> cnt;
	vector<ll> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
		if(cnt[a[i]]%k) a[i] = hsh(a[i]);
		else a[i] = 1LL*(-k+1)*hsh(a[i]);
	}
	for(int i=1;i<=n;i++){
		a[i]+=a[i-1];
	}
	while(q--){
		int l,r;cin>>l>>r;
		cout<<(a[r]==a[l-1]);
	}
	cout<<"\n";
	

	return 0;
}
