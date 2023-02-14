#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct node {
    int n;
    node* lc=nullptr;
    node* rc=nullptr;
    bool rev = 0;
    int lev = rand();
    int size = 1;
};

int size(node* c) {
    if(c==nullptr) return 0;
    return c->size;
}

void tag(node* c) {
    if(c==nullptr) return ;
    c->rev^=1;
}

void push(node* c) {
    if(c==nullptr) return ;
    if(c->rev) {
        tag(c->lc);
        tag(c->rc);
        swap(c->lc,c->rc);
    }
    c->rev = 0;
}

void pull(node* c) {
    if(c==nullptr) return ;
    c->size = size(c->lc)+size(c->rc)+1;
}

pair<node*,node*> split(node* x,int k) {
    push(x);
    pair<node*,node*> ans = {nullptr,nullptr};
    if(x==nullptr) return ans;
    if(size(x->lc)>=k) {
        auto tp  = split(x->lc,k);
        x->lc = tp.second;
        pull(x);
        return {tp.first,x};
    } else {
        auto tp = split(x->rc,k-size(x->lc)-1);
        x->rc = tp.first;
        pull(x);
        return {x,tp.second};
    }
}

node* merge(node* x,node* y) {
    push(x);
    push(y);
    if(x==nullptr || y==nullptr) {
        return (x==nullptr)?(y):(x);
    }
    if(x->lev>y->lev) {
        node* k = merge(x,y->lc);
        y->lc = k;
        pull(y);
        return y;
    } else {
        node* k = merge(x->rc,y);
        x->rc = k;
        pull(x);
        return x;
    }
}

void print(node* c){
	push(c);
	if(c==nullptr) return;
	print(c->lc);
	cout<<c->n<<" ";
	print(c->rc);
}

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    int q;
    cin>>q;
    node* arr = new node;
    arr->n = 1;
    for(int i=2; i<=n; i++) {
        node* temp = new node;
        temp->n = i;
        arr = merge(arr,temp);
    }

    while(q--) {
        string s;
        cin>>s;
        if(s[0]=='R') {
            int l,r;
            cin>>l>>r;
            auto fp = split(arr,l-1);
            auto sp = split(fp.second,r-l+1);
            tag(sp.first);
            arr = merge(fp.first,sp.first);
            arr = merge(arr,sp.second);
        } else {
            int l1,r1,l2,r2;
            cin>>l1>>r1>>l2>>r2;
            auto fp = split(arr,l1-1);
            auto sp = split(fp.second,r1-l1+1);
            auto tp = split(sp.second,l2-r1-1);
            auto frp = split(tp.second,r2-l2+1);
            arr = merge(fp.first,frp.first);
            arr = merge(arr,tp.first);
            arr=merge(arr,sp.first);
            arr = merge(arr,frp.second);
        }
    }
	print(arr);
	cout<<"\n";
    return 0;
}
