#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k;cin>>n>>k;
	bitset<30> arr[n];
	for(int i=0;i<n;i++){
		arr[i].reset();
		string s;cin>>s;	
		for(int j=0;j<s.size();j++) arr[i][j] = (s[j]=='1');
	}
	int ans = INT_MAX;	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			ans = min((int)(arr[i]^arr[j]).count(),ans);
		}
	}
	cout<<ans<<"\n";
	return 0;
}
