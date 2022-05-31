//gready the smallest
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    int v;
    node* l=nullptr;
    node* r=nullptr;
};
inline int minofneighbor(node* n){
    int minn=INT_MAX;
    minn = ((n->l)==nullptr) ? minn:min(minn,(n->l)->v);
    minn = ((n->r)==nullptr) ? minn:min(minn,(n->r)->v);
    return minn;
}
void deletenode(node* n){
    if(n->r!=nullptr) (n->r)->l = n->l;
    if(n->l!=nullptr) (n->l)->r = n->r;
    delete(n);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    node* head=new node;
    cin>>head->v;
    node* sorted[n];
    sorted[0]=head;
    for(int i=1;i<n;i++){
        node* temp=new node;
        cin>>temp->v;
        temp->l = sorted[i-1];
        sorted[i-1]->r=temp;
        sorted[i]=temp;
    }
    sort(sorted,sorted+n,[](node* a,node* b){return a->v<b->v;});
    ll ans=0;
    for(int i=0;i<n-1;i++){
        ans+=minofneighbor(sorted[i]);
        deletenode(sorted[i]);
    }
    cout<<ans<<endl;
    return 0;
}