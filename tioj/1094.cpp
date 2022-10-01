#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::



vector<int> basis;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	while(cin>>n && n){
		basis.clear();
		while(n--){
			int x;cin>>x;
			for(auto v :  basis){
				x = min(x,x^v);
			}
			if(x) basis.push_back(x);
		}
		int ans=0;
		for(auto v : basis){
			ans = max(ans,ans^v);
		}
		cout<<ans<<"\n";
	}

	return 0;
}
