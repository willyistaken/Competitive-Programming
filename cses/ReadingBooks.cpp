#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	ll maxn = 0;
	ll sum = 0;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		maxn = max(maxn,1LL*a);
		sum+=a;
	}
	cout<<max(sum,maxn*2)<<"\n";
	return 0;
}
