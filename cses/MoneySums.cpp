#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds



bitset<100005> dp;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	dp[0]=1;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		dp |= (dp<<a);
	}
	vector<int> arr;
	for(int i=1;i<100005;i++) if(dp[i]) arr.push_back(i);
	cout<<arr.size()<<"\n";
	for(auto i : arr) cout<<i<<" ";
	cout<<"\n";
	return 0;
}
