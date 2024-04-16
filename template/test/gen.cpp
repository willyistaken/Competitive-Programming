#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	mt19937 r(random_device{}());
	int n = 5;
	vector<int> arr(2*n);
	srand(r());
	for(int i=0;i<2*n;i++) arr[i]=i+1;
	cout<<n<<"\n";
	random_shuffle(arr.begin(),arr.end());
	for(int i=0;i<2*n;i+=2){
		if(arr[i]>arr[i+1]) swap(arr[i],arr[i+1]);
		cout<<arr[i]<<" "<<arr[i+1]<<"\n";
	}


	return 0;
}
