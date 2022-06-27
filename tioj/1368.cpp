#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct	smallms{
	int l;
	int r;
	int n;
};
smallms comp(const smallms &a,const smallms &b){
	if(a.l<b.l) return a;
	if(b.l<a.l) return b;
	if(a.r<b.r) return a;
	return b;
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	while(cin>>n){
	ll sum[n+1]={0};
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sum[i+1] = sum[i]+arr[i];
	}
	pair<int,int> range[n];
	stack<int> mono;
	for(int i=0;i<n;i++){
		while(!mono.empty() && arr[mono.top()]>=arr[i]){
			mono.pop();	
		}
		range[i].first = (mono.empty()) ? 0:mono.top()+1;
		mono.push(i);
	}
	while(!mono.empty()) mono.pop();
	for(int i=n-1;i>=0;i--){
		while(!mono.empty() && arr[mono.top()]>=arr[i]){
			mono.pop();
		}
		range[i].second = (mono.empty()) ? n-1:mono.top()-1;
		mono.push(i);
	}
	smallms  maxn = {0,0,0};
	for(int i=0;i<n;i++){
		if((sum[maxn.r+1]-sum[maxn.l])*arr[maxn.n]<(sum[range[i].second+1]-sum[range[i].first])*arr[i]){
			maxn = {range[i].first,range[i].second,i};
		}
		if((sum[maxn.r+1]-sum[maxn.l])*arr[maxn.n]==(sum[range[i].second+1]-sum[range[i].first])*arr[i]){
			maxn = comp(maxn,{range[i].first,range[i].second,i});
		}
	}
	cout<<(sum[maxn.r+1]-sum[maxn.l])*arr[maxn.n]<<"\n";
	cout<<maxn.l+1<<" "<<maxn.r+1<<"\n";
	}
	return 0;
}
