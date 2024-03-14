#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	vector<vector<int> > arr(n,vector<int>(2,0));
	for(int i=0;i<n;i++){
		cin>>arr[i][0]>>arr[i][1];
	}
	ll maxn = -1e10;
	vector<int> l(n);
	for(int m=0;m<(1<<n);m++){
		for(int i=0;i<n;i++){
			l[i]=arr[i][(m>>i)&1];
		}
		sort(l.begin(),l.end());
		ll prev = -1e9;
		ll minn = 1e10;
		for(auto i : l){
			minn = min(i-prev,minn)	;
			prev=i;
		}
		maxn = max(maxn,minn);
	}
	cout<<maxn<<"\n";

	return 0;
}
