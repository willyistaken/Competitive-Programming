#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
bool can(int m,vector<int> narr){
	int lhead=0;
	for(int i=n-1;i>=0;i--){
		if(narr[i]>m){
			int takeoff = narr[i]-m;
			while(takeoff){
				if(lhead>=n) return false;
				if(narr[lhead]+2*takeoff<=m){
					narr[lhead]+=2*takeoff;
					takeoff=0;
				}else{
					takeoff-=(m-narr[lhead])/2;
					narr[lhead]=m;
					lhead++;
				}
			}
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n;
		int m;cin>>m;
		vector<int> arr(n,0);
		for(int i=0;i<m;i++) {
			int k;cin>>k;
			k--;arr[k]++;
		}
		sort(arr.begin(),arr.end());
		int l=0;int r=2*m;
		while(r-l>1){
			int mid = (r+l)/2;
			if(can(mid,arr)){
				r=mid;
			}else{
				l=mid;
			}
		}
		cout<<r<<"\n";
	}

	return 0;
}
