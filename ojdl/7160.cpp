#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,k,d;cin>>n>>m>>k>>d;
	int arr[n];
	vector<int> day;
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<d;i++){
		int a;cin>>a;
		day.push_back(a);
	}
	sort(arr,arr+n,greater<int>());
	sort(day.begin(),day.end());
	ll ans=0;
	k = min(n,k);
	k = min(m-d,k);
	int bp = d-1;
	for(int i=0;i<k;i++) ans+=arr[i];
	for(int j=m;j>=0 && k>0 ;j--){
		if(j==day[bp]){
			bp--;
		}else{
			ans+=j;
			k--;
		}
	}
	cout<<ans<<"\n";

	return 0;
}
