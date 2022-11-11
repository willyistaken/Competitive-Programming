#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,k;cin>>n>>m>>k;
	int arr[n];
	int des[m];
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<m;i++) cin>>des[i];
	sort(arr,arr+n);
	sort(des,des+m);
	int l = 0;
	int ans = 0;
	for(int i=0;i<m;i++){
		while(l<n && arr[l]<des[i]-k) l++;
		if(l<n && arr[l]<=des[i]+k){
			ans++;
			l++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
