#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

int n;
vector<int>  arr;

bool check(int m){
	int k = m;
	for(int i = n-1;i>=(m-1);i--){
		if(arr[i]<=k) k--;	
		if(k<=0) return 1;
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n;
		arr.resize(n);
		for(int i=0;i<n;i++) cin>>arr[i];
		sort(arr.begin(),arr.end());
		int l = 0;int r = n+1;
		while(r-l>1){
			int mid = (r+l)/2;
			if(check(mid)) l = mid;
			else r = mid;
		}
		cout<<l<<"\n";
	}

	return 0;
}
