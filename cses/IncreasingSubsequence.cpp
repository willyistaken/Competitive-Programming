#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	vector<int> arr;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		auto it = lower_bound(arr.begin(),arr.end(),a);
		if(it==arr.end()) arr.push_back(a);
		else arr[it-arr.begin()]=a;
	}
	cout<<arr.size()<<"\n";

	return 0;
}
