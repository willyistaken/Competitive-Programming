#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


struct node{
	node* child[2]={nullptr,nullptr};
};

node trie;

void insert(int x){
	node* cur = &trie;
	for(int i=7;i>=0;i--){
		if(cur->child[(x>>i)&1]==nullptr){
			cur->child[(x>>i)&1]= new node;	
		}
		cur = cur->child[(x>>i)&1];
	}
}

int query(int x){
	node* cur = &trie;
	ll ans = 0;
	for(int i=7;i>=0;i--){
		if(cur->child[!((x>>i)&1)]==nullptr){
			cur = cur->child[(x>>i)&1];
		}else{
			ans+=(1<<i);
			cur = cur->child[!((x>>i)&1)];
		}
	}
	return ans;
}

void del(node *k){
	if(k==nullptr) return;
	del(k->child[0]);
	del(k->child[1]);
	delete k;
	k = nullptr;
}

void solve(){
	trie.child[0]=nullptr;
	trie.child[1]=nullptr;
	int n;cin>>n;
	int arr[n+1];
	for(int i=1;i<=n;i++) cin>>arr[i];
	arr[0]=0;
	for(int i=1;i<=n;i++) arr[i] = arr[i]^arr[i-1];
	insert(arr[0]);
	int ans = 0;
	for(int i=1;i<=n;i++){
		ans = max(ans,query(arr[i]));
		insert(arr[i]);
	}
	cout<<ans<<"\n";
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
