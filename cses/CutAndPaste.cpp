#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct treap{
	char c;
	int size,prio;
	treap* l;
	treap* r;
	treap(char a){
		c = a;	
		size = 1;
		prio = rand();
		l = nullptr,r = nullptr;
	}
};
int size(treap* a){
	return (a==nullptr)?(0):(a->size);
}

void split(treap* root,treap* &l,treap* &r,int val){
	if(root==nullptr){
		l =nullptr;r = nullptr;
		return;
	}
	if(size(root->l)<val){
		split(root->r,root->r,r,val-size(root->l)-1);	
		l = root;	
	}else{
		split(root->l,l,root->l,val);
		r = root;
	}
	root->size = 1+size(root->l)+size(root->r);
}

void merge(treap* &root,treap* l,treap* r){
	if(l==nullptr || r==nullptr){
		if(l==nullptr){
			(root = r);
		}else{
			(root = l);
		}
		return ;
	}
	if(l->prio<r->prio){
		merge(l->r,l->r,r);
		root = l;
	}else{
		merge(r->l,l,r->l);
		root = r;
	}
	root->size=  1 + size(root->l)+size(root->r);	
}

void print(treap* cur){
	if(cur==nullptr) return;
	print(cur->l);
	cout<<cur->c;
	print(cur->r);
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	string s;cin>>s;
	treap* arr = new treap(s[0]);
	for(int i=1;i<n;i++) {
		treap* temp = new treap(s[i]);
		merge(arr,arr,temp);
	}
	
	while(q--){
		int a,b;cin>>a>>b;
		treap* f = new treap(' ');
		treap* s = new treap(' ');
		treap* t = new treap(' ');
		split(arr,f,s,a-1);
		split(s,s,t,b-a+1);
		merge(arr,f,t);
		merge(arr,arr,s);
	}
	print(arr);
	cout<<"\n";
	return 0;
}
