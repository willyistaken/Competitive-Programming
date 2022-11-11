#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int x;cin>>x;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	sort(arr,arr+n);
	int l = 0;
	int r = n-1;
	int ans = 0;
	while(l<=r){
		int k = x-arr[r];
		r--;
		if(k>=arr[l]){
			l++;
		}
		ans++;
	}
	cout<<ans<<'\n';
	return 0;
}
