#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int arr[8] = {1,1,2,2,3,3,3,4};
	cout<<unique(arr,arr+8)-arr;
	for(auto i : arr) cout<<i<<" ";
	cout<<"\n";
	return 0;
}
