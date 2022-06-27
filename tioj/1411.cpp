#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	while(cin>>n){
	int sum[n+1]={0};
	for(int i=0;i<n;i++){
		int  a;cin>>a;
		if(a) sum[i+1]  = (a>0) ? 1+sum[i]:-1+sum[i];
		else sum[i+1]=sum[i];
	}
	map<int,int> ft;
	map<int,int> sd;
	for(int i=0;i<=n;i++){
		if(ft.count(sum[i])==0) ft.insert({sum[i],i});	
		sd[sum[i]] = i;
	}
	int maxn=INT_MIN;
	for(auto i : ft){
		maxn = max(maxn,sd[i.first]-i.second);
	}
	cout<<maxn<<"\n";
	}
	return 0;
}
