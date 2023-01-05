#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


struct node{
	char c = ' ';
	node* l;
	node* r;
	bool tag = 0;
	int size;int proi;
	node(char a= ' '){
		c = a;
		l =nullptr;
		r = nullptr;
		size = 1;
		proi = rand();
	}
};

int size(node* t){
	return (t==nullptr)?0:t->size;
}
void flip(node* t){
	if(t==nullptr) return;
	t->tag^= 1;
}
void push(node* t){
	if(t==nullptr) return;
	if(t->tag){
		swap(t->l,t->r);	
		flip(t->l);
		flip(t->r);
	}
	t->tag = 0;
}

void pull(node* t){
	if(t==nullptr) return;
	t->size = 1+size(t->r)+size(t->l);
}

node* merge(node* a,node* b){
	push(a);push(b);
	if(a==nullptr || b==nullptr){
		return (a==nullptr)?(b):(a);
	}
	if(a->proi<b->proi){
		a->r = merge(a->r,b);
		pull(a);	
		return a;
	}else{
		b->l = merge(a,b->l);
		pull(b);
		return b;
	}
}
pair<node*,node*> split(node* x,int v){
	push(x);
	pair<node*,node*> ans  = {nullptr,nullptr};
	if(x==nullptr) return ans;
	if(size(x->l)<v){
		ans = split(x->r,v-size(x->l)-1);	
		x->r = ans.first;			
		pull(x);
		ans.first = x;
	}else{
		ans = split(x->l,v);
		x->l  = ans.second;
		pull(x);
		ans.second = x;
	}
	return ans;
}

void print(node* a){
	if(a==nullptr) return;
	push(a);
	print(a->l);
	if(a->c) cout<<a->c;
	print(a->r);
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;	
	string s;cin>>s;
	node* arr =  new node(s[0]);
	for(int i=1;i<=n;i++) arr = merge(arr,new node(s[i]));
	while(q--){
		int l,r;cin>>l>>r;
		auto temp = split(arr,l-1);
		auto temp2 = split(temp.second,r-l+1);	
		flip(temp2.first);	
		arr = merge(temp.first,temp2.first);
		arr = merge(arr,temp2.second);
	}
	print(arr);
	cout<<"\n";
	return 0;
}
