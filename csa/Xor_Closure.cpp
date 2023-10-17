#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	vector<ll> basis;
	for(int i=0;i<n;i++){
		ll a;cin>>a;
		for(auto k : basis){
			if((a^k)<a) a = a^k;
		}
		if(a) basis.push_back(a);
	}
	int g = basis.size();
	cout<<(1LL<<g)-n<<"\n";

	return 0;
}
