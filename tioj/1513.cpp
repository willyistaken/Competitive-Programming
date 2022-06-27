#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	while(cin>>n){
		map<int,int> s;
		ll ans=0;
		for(int i=0;i<n;i++){
			ll k;cin>>k;
			ans^=k;
		}
		cout<<ans<<"\n";
	}

	return 0;
}
