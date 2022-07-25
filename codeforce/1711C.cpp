#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n,m,k;cin>>n>>m>>k;
		int arr[k];
		for(int i=0;i<k;i++) cin>>arr[i];
		sort(arr,arr+k);
		int now=n;
		for(int i=0;i<k;i++){
			if((arr[i]/m) >= 2){
				now-=arr[i]/m;
			}
			if(now<=1) break;
		}
		if(now<=0){
			cout<<"Yes\n";
			continue;
		}
		now = m;
		for(int i=0;i<k;i++){
			if((arr[i]/n)>=2){
				now-=arr[i]/n;
			} 
			if(now<=1) break;
		}
		if(now<=0){
			cout<<"Yes\n";
			continue;
		}
		sort(arr,arr+k,greater<int>());
		now=n;
		for(int i=0;i<k;i++){
			if((arr[i]/m) >= 2){
				now-=arr[i]/m;
			}
			if(now<=1) break;
		}
		if(now<=0){
			cout<<"Yes\n";
			continue;
		}
		now = m;
		for(int i=0;i<k;i++){
			if((arr[i]/n)>=2){
				now-=arr[i]/n;
			} 
			if(now<=1) break;
		}
		if(now<=0){
			cout<<"Yes\n";
			continue;
		}
		cout<<"No\n";
	}

	return 0;
}
