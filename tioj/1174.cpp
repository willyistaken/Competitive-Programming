#include <bits/stdc++.h>
using namespace std;

int main(){

	int n,m;cin>>n>>m;
	vector<int> arr1(n,0);
	vector<int> arr2(m,0);
	for(int i=0;i<n;i++){
		cin>>arr1[i];

	}
	for(int i=0;i<m;i++){
	 cin>>arr2[i];
	}
	sort(arr1.begin(),arr1.end());
	sort(arr2.begin(),arr2.end());
	int minn= INT_MAX;
	for(int i=0;i<n;i++){
		auto it = lower_bound(arr2.begin(),arr2.end(),arr1[i]);
		if(it!=arr2.begin()) minn = min({abs(arr2[it-arr2.begin()]-arr1[i]),abs(arr2[it-arr2.begin()-1]-arr1[i]),minn});
		minn = min(minn,abs(arr2[it-arr2.begin()]-arr1[i]));
	}
	cout<<minn<<endl;
}
