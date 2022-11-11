#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	vector<int> arr(n);
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		arr[i]^=arr[i-1];
	}
		
	cout<<"\n";

	return 0;
}
