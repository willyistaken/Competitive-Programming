#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	stack<int> mono;
	for(int i=0;i<n;i++){
		while(mono.size()){
			if(arr[mono.top()]<arr[i]) break;
			mono.pop();
		}
		int v= (mono.size())?(mono.top()):(-1);
		cout<<v+1<<" \n"[i==n-1];	
		mono.push(i);
	}

	return 0;
}
