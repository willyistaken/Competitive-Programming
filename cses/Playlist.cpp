#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	map<int,int> latest;
	int ans = 1;
	int now = 1;
	int a;cin>>a;latest.insert({a,0});
	for(int i=1;i<n;i++){
		int a;cin>>a;
		now++;
		if(latest.count(a)) now = min(now,i-latest[a]);
		ans= max(now,ans);
		latest[a] = i;
	}
	cout<<ans<<"\n";
	return 0;
}
