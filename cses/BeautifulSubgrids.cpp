#pragma GCC target("popcnt")
#pragma GCC optimize(" unroll-loops")
#pragma gcc optimize("Ofast")
#pragma GCC optimization("Ofast")
#pragma optimize(Ofast)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	bitset<3000> arr[n];
	for(int i=0;i<n;i++){
		arr[i].reset();
		string s;cin>>s;	
		for(int j=0;j<n;j++) arr[i][j] = (s[j]=='1');
	}
	ll ans = 0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int s = (arr[i]&arr[j]).count();
			ans+=(1LL*s*s-s)/2;
		}
	}
	cout<<ans<<"\n";

	return 0;
}
