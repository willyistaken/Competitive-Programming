#include<bits/stdc++.h>
using namespace std;
#define ll long long



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	while(cin>>n){
	map<int,int> mp;
	for(int i=0;i<n;i++){
		int l,r;cin>>l>>r;
		if(mp.count(l)) mp[l]+=1;
		else mp.insert({l,1});
		if(mp.count(r+1)) mp[r+1]-=1;
		else mp.insert({r+1,-1});
	}
	int ans=0;
	int maxn=0;
	for(auto i : mp){
		ans+=i.second;
		maxn=max(ans,maxn);
	}
	cout<<maxn<<endl;
	}
	return 0;
}
