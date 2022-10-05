#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
	//__gnu_pbds::

struct people{
	int a;
	int b;
};

// cool problem:
/*
monotonic queue can be use when b>c and a>b then a>c ,thie is a more loose requirement

*/

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int ans[n]={0};
	people arr[n];
	for(int i=0;i<n;i++) cin>>arr[i].a>>arr[i].b;
	stack<int> mono;

	for(int i=0;i<n;i++){
		while(mono.size()){
			if((arr[mono.top()].a<arr[i].a && arr[mono.top()].b<=arr[i].b) || (arr[mono.top()].a<=arr[i].a && arr[mono.top()].b<arr[i].b)) mono.pop();
			else break;
		}
		int len = (mono.size())?(i-mono.top()-1):(i);
		ans[i]+=len;
		mono.push(i);
	}
	while(mono.size()) mono.pop();
	int result=0;
	for(int i=n-1;i>=0;i--){
		while(mono.size()){
			if((arr[mono.top()].a<arr[i].a && arr[mono.top()].b<=arr[i].b) || (arr[mono.top()].a<=arr[i].a && arr[mono.top()].b<arr[i].b)) mono.pop();
			else break;
		}
		int len = (mono.size())?(mono.top()-i-1):(n-i-1);
		ans[i]+=len;
		result = max(ans[i],result);
		mono.push(i);
	}
	cout<<result<<"\n";


	return 0;
}
