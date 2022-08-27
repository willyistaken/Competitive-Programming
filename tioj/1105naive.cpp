#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::

ll dis(pair<int,int> a,pair<int,int> b){
	return 1LL*(a.first-b.first)*(a.first-b.first)+1LL*(a.second-b.second)*(a.second-b.second);
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	while(cin>>n){
		if(n==0) break;
		pair<int,int> arr[n];
		for(int i=0;i<n;i++){
				cin>>arr[i].first>>arr[i].second;
		}
		pair<int,int> ans;
		ll maxdis=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(dis(arr[i],arr[j])>maxdis) {
					ans = {i,j};
					maxdis = dis(arr[i],arr[j]);
				}
			}
		}
		cout<<ans.first<<" "<<ans.second<<"\n";
	}

	return 0;
}
