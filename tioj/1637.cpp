#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	n--;
	int h[n];
	int l[n];
	int r[n];
	for(int i=0;i<n;i++) cin>>h[i];
	stack<int> mono;
	for(int i=0;i<n;i++){
		while(mono.size()){
			if(h[mono.top()]>=h[i]) break;
			mono.pop();
		}
		l[i] = ((mono.size()) ? (mono.top()+1):0);
		mono.push(i);
	}
	while(mono.size()) mono.pop();
	for(int i=n-1;i>=0;i--){
		while(mono.size()){
			if(h[mono.top()]>h[i]) break;
			mono.pop();
		}
		r[i] = ((mono.size())?(mono.top()-1):n-1);
		mono.push(i);
	}
	ll ans=0;
	for(int i=0;i<n;i++){
		ans+= 1LL*h[i]*(i-l[i]+1)*(r[i]-i+1);
	}
	cout<<ans<<"\n";
	return 0;
}
