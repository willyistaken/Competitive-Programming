#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	multiset<int> towers;
	for(int i=0;i<n;i++){
		auto it = towers.upper_bound(arr[i]);
		if(it!=towers.end()){
			towers.erase(it);
			towers.insert(arr[i]);
		}else{
			towers.insert(arr[i]);
		}
	}
	cout<<towers.size()<<"\n";

	return 0;
}
