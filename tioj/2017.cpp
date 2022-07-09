#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	ll sum[n+1]={0};
	for(int i=0;i<n;i++){
		int k;cin>>k;
		sum[i+1] = sum[i]+k;
	}
	ll ans=0;
	stack<ll> mono;
	for(int i=n;i>=0;i--){
		while(!mono.empty()){
			if(sum[mono.top()]<sum[i]){
				break;
			}
			mono.pop();
		}
		if(!mono.empty()){
			ans+=n-mono.top()+1;
		}
		mono.push(i);
	}
	cout<<ans<<"\n";
	return 0;
}
