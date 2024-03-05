#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
int n,t;
vector<int> arr;


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>t;
	arr.resize(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
		arr[i]%=t;
	}
	sort(arr.begin(),arr.end());
	arr.resize(unique(arr.begin(),arr.end())-arr.begin());
	int maxn = 1e9;
	int k = arr.size();
	for(int i=0;i<k-1;i++){
		int dis = arr[i]-arr[(i+1)%k]; 
		dis+=t;	
		maxn = min(maxn,dis);
	}
	maxn = min(maxn,arr[k-1]-arr[0]);
	cout<<(maxn+1)/2<<"\n";
	return 0;
}
