#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
struct node{
	node* child[26];
	int cnt = 0;
	node(){
		fill(child,child+26,nullptr);
		cnt = 0;
	}
};

node head;
void add(string &s){
	node* cur = &head;
	for(auto i : s)	{
		if(cur->child[i-'a']==nullptr) cur->child[i-'a'] = new(node);
		cur->child[i-'a']->cnt++;
		cur = cur->child[i-'a'];
	}
}

ll query(string &s){
	node* cur = &head;
	ll ans = 0;
	for(auto i : s){
		if(cur->child[i-'a']==nullptr)	 return  ans;
		ans+=cur->child[i-'a']->cnt;
		cur = cur->child[i-'a'];
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;	
	vector<string> arr(n);
	ll totalans = 0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		totalans+=(1LL*(n)*arr[i].size());
	}
	vector<string> rarr(n);
	for(int i=0;i<n;i++){
		int sz = arr[i].size();
		for(int k=sz-1;k>=0;k--) rarr[i].push_back(arr[i][k]);
	}
	cout<<totalans<<"\n";
	for(int i=0;i<n;i++) add(arr[i]);
	for(int i=0;i<n;i++) totalans-=query(rarr[i]);
	cout<<2*totalans<<"\n";
	return 0;
}
