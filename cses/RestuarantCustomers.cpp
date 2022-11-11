#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	pair<int,int> arr[2*n];
	for(int i=0;i<2*n;i+=2){
		cin>>arr[i].first;
		arr[i].second = 1;
		cin>>arr[i+1].first;
		arr[i+1].first+=1;
		arr[i+1].second = -1;
	}
	sort(arr,arr+2*n);
	int ans = 0;	
	int sum = 0;
	int prev= -1;
	for(int i=0;i<2*n;i++){
		if(arr[i].first==prev){
			sum+=arr[i].second;
		}else{
			ans = max(sum,ans);
			sum+=arr[i].second;
			prev = arr[i].first;
		}
	}
	ans = max(sum,ans);
	cout<<ans<<"\n";

	return 0;
}
