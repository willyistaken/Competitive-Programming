//性質: treap的中序遍歷等於序列順序
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
    node* lc=nullptr;
    node *rc=nullptr;
    int v;
};
void dfs(node* root){
    if(root==nullptr) return;
    cout<<root->v<<" ";
    dfs(root->lc);
    dfs(root->rc);
    delete(root);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    while(cin>>n && n){
    stack<node*> rightlink;
    node* root=nullptr;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        node* temp = new node;
        temp->v=a;
        while(!rightlink.empty()){
            if(rightlink.top()->v<a) break;
            rightlink.pop();
        }
        if(rightlink.empty()&&root==nullptr){
            rightlink.push(temp);
            root=temp;
            continue;
        }
        if(rightlink.empty()){
            temp->lc = root;
            rightlink.push(temp);
            root = temp;
            continue;
        }
        if(rightlink.top()->v<a){
            node* orc = rightlink.top()->rc;
            rightlink.top()->rc = temp;
            temp->lc = orc;
            rightlink.push(temp);
        }
    }
    dfs(root);
    cout<<"\n";
    }




    return 0;
}