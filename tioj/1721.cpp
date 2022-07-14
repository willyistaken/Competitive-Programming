#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	while(cin>>n){
		int a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		int l[n]={0};
		int r[n]={0};
		stack<int> mono;
		for(int i=0;i<n;i++){
			while(!mono.empty()){
				if(a[mono.top()]>=a[i]) break;
				mono.pop();
			}
			l[i] = (mono.empty()) ? 0:mono.top();
			mono.push(i);
		}
		while(mono.size()) mono.pop();
		for(int i=n-1;i>=0;i--){
			while(!mono.empty()){
				if(a[mono.top()]>=a[i]) break;
				mono.pop();
			}
			r[i] = (mono.empty()) ? n-1:mono.top();
			mono.push(i);
		}
		for(int i=0;i<n;i++){
			cout<<r[i]-l[i]+1<<" \n"[i==n-1];
		}
	}

	return 0;
}
