#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	vector<int> arr;
	int inp[n];
	for(int i=0;i<n;i++){
		cin>>inp[i];
		int b = upper_bound(arr.begin(),arr.end(),inp[i])-arr.begin();
		if(b>=arr.size()) arr.push_back(inp[i]);
		else{
			arr[b] = inp[i];
		}
	}
	int k = arr.size();
	int g = k;
	vector<vector<int> > ans(k);
	bool take[n+1]={0};
	while(g==k){	
		int prev[n+1]={0};
		arr.clear();
		for(int i=0;i<n;i++){
			if(take[inp[i]]) continue;
			int b = upper_bound(arr.begin(),arr.end(),inp[i])-arr.begin();
			if(b>=arr.size()) arr.push_back(inp[i]);
			else{
				arr[b] = inp[i];
			}
			if(b) prev[inp[i]] = arr[b-1];
		}
		if((g=arr.size())!=k) break;
		int cur = arr.back();
		for(int m=k-1;m>=0;m--){
			ans[m].push_back(cur);
			take[cur]=1;
			cur = prev[cur];
		}
	}
	int p = ans[0].size();
	cout<<p<<" "<<k<<"\n";
	vector<vector<int> > realans(p);
	int convert[n+1];
	for(int i=0;i<n;i++){
		convert[inp[i]]=i+1;
	}
	for(int i=0;i<p;i++){
		for(int j=0;j<k;j++){
			realans[i].push_back(convert[ans[j][i]]);
		}
	}
	sort(realans.begin(),realans.end());
	for(auto v : realans){
		for(auto i : v){
			cout<<i<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
