#include<bits/stdc++.h>
using namespace std;
#define ll long long



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int arr[n+1];
	for(int i=1;i<n+1;i++){
		cin>>arr[i];
	}
	int q;cin>>q;
	for(int i=0;i<q;i++){
		int it,time;cin>>it>>time;
		while(time--){
			it=arr[it];
		}
		cout<<it<<endl;
	}
	return 0;
}
