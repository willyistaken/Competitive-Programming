#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

int calc(vector<int> &l){
	vector<int> arr;
	reverse(l.begin(),l.end());
	for(auto i : l){
		int b = upper_bound(arr.begin(),arr.end(),i)-arr.begin();
		if(b>=arr.size()) arr.push_back(i);
		else arr[b]=i;
	}
	reverse(l.begin(),l.end());
	//cout<<arr.size();
	return arr.size();
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	vector<int> arr;
	for(int i=0;i<n;i++) arr.push_back(i);
	ll ans = 0;
	do{
		ans+=calc(arr);	
	}while(next_permutation(arr.begin(),arr.end()));
	cout<<ans<<"\n";
	return 0;
}
