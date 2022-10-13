#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int m,n;cin>>n>>m;
	int r= 1;
	int ans=0;
	for(int i=1;i<m;i++) if(__gcd(i,m)==1) ans+=1;
	cout<<ans<<"\n";
	for(int i=0;i<=100;i++){
		cout<<i<<" "<<r<<"\n";
		r = (1LL*n*r)%m;
	}

	return 0;
}
