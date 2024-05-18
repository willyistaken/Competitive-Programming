#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n = 200;
	int H = 100;
	mt19937 rng(random_device{}());
	int a = rng()%(n+1);
	vector<int> arr(a);	
	for(int i=0;i<a;i++){
		arr[i] = rng()%(H+1);
	}
	vector<int> ar(n-a);
	for(int i=0;i<n-a;i++){
		ar[i] = rng()%(H+1);
	}
	sort(arr.rbegin(),arr.rend());
	sort(ar.begin(),ar.end());
	cout<<n<<"\n";
	for(auto i : arr) cout<<i<<" ";
	for(auto i : ar) cout<<i<<" ";
	cout<<"\n";

	return 0;
}
