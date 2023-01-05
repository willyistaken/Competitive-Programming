#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


struct node{
	int v = 0;
	node* l;
	node* r;
	bool tag = 0;
	int size;int proi;
	ll sum = 0;
	node(int g = 0){
		v = g;
		sum = v;
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
ll sum(node* t){
	return (t==nullptr)?(0):t->sum;
}
void pull(node* t){
	if(t==nullptr) return;
	t->size = 1+size(t->r)+size(t->l);
	t->sum = t->v+sum(t->l)+sum(t->r);
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


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	int temp;cin>>temp;
	node* arr = new node(temp);
	for(int i=1;i<n;i++){
		cin>>temp;
		arr= merge(arr,new node(temp));
	}
	while(q--){
		int ty;cin>>ty;
		int l,r;cin>>l>>r;
		node* a;
		node* b;
		node* c;
		auto temp = split(arr,l-1);
		a = temp.first;
		auto temp2 = split(temp.second,r-l+1);	
		b = temp2.first;
		c = temp2.second;
		if(ty==1){
			flip(b);
		}else{
			cout<<sum(b)<<"\n";
		}
		arr = merge(a,b);
		arr = merge(arr,c);
	}
	return 0;
}


