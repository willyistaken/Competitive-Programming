#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

struct node{
	int ch[2]={0};
};
vector<node> tree;
vector<int> father;
int query(int a){
	if(father[a]==a) return a;
	father[a] = query(father[a]);
	return father[a];
}
void join(int a,int b){
	father[query(a)] = query(b);
	return ;
}
vector<int> result;
void dfsf(int r){
	result.push_back(r);
	if(tree[r].ch[0]) dfsf(tree[r].ch[0]);
	if(tree[r].ch[1]) dfsf(tree[r].ch[1]);
}

void dfsm(int r){
	if(tree[r].ch[0]) dfsm(tree[r].ch[0]);
	result.push_back(r);
	if(tree[r].ch[1]) dfsm(tree[r].ch[1]);
}

void dfsb(int r){
	if(tree[r].ch[0]) dfsb(tree[r].ch[0]);
	if(tree[r].ch[1]) dfsb(tree[r].ch[1]);
	result.push_back(r);
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,q;cin>>n>>q;
	tree.resize(n+1);
	father.resize(n+1);
	for(int i=0;i<=n;i++){
		father[i] = i;
	}
	for(int i=2;i<=n;i++){
		int p,t;cin>>p>>t;
		tree[p].ch[t]=i;
	}	

	result.clear();
	dfsf(1);
	for(int i=0;i<n/2;i++){
		join(result[i],result[n-i-1]);
		
	}	
	
	result.clear();
	dfsm(1);
	for(int i=0;i<n/2;i++){
		join(result[i],result[n-i-1]);
	}
	result.clear();
	dfsb(1);
	for(int i=0;i<n/2;i++){
		join(result[i],result[n-i-1]);
	}
	vector<bool> cnt(n+1,0);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(!cnt[query(i)]) ans++;
		cnt[query(i)]=1;
	}	
	cout<<ans<<"\n";
	while(q--){
		int a,b;cin>>a>>b;
		//cout<<query(a)<<" "<<query(b)<<"\n";
		if(query(a)!=query(b)) ans--;
		cout<<ans<<"\n";
		join(a,b);
	}
}
