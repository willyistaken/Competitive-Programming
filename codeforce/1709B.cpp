#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	ll forward[n];
	ll backward[n];
	forward[0]=0;
	backward[n-1]=0;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=1;i<n;i++){
		forward[i] = forward[i-1]+((arr[i]<arr[i-1])?(arr[i-1]-arr[i]):(0));
	}
	for(int i=n-2;i>=0;i--){
		backward[i]= backward[i+1] + ((arr[i]<arr[i+1])?(arr[i+1]-arr[i]):(0));
	}
	while(m--){
		int s,t;cin>>s>>t;
		if(s>t){
			cout<<backward[t-1]-backward[s-1]<<"\n";	
		}else{
			cout<<forward[t-1]-forward[s-1]<<"\n";	
		}
	}
	return 0;
}
