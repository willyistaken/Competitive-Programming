#include <bits/stdc++.h>
using namespace std;
struct node{
    node* next;
    node* prev;
    int index;
};
int n;int group[1000000]={0};
node* lastofgroup(int x,node start){
    if(group[start.index]==x && group[(*start.next).index]!=x){
        return  start;
    }else{
        return lastofgroup(x,start.next);
    }
}
vector<node> bignodelist[1000000];
int main(){
    cin>>n;
    for(int i=1;i<n+1;i++){
        int k;cin>>k;
        for(int j=0;j<k;j++){
            int index;cin>>index;
            group[index]=i;
        }
    }
    int command;cin>>command;
    *node first;*node last;
    while(command--){
        string co;cin>>co;
        
        if(co[0]=='D'){
            cout<<first.index<<endl;
        }else{
            int num;cin>>num; 
            if(bignodelist.empty()){
               
               node a;
               a.index=num;
               a.prev=NULL;
               a.next=NULL;
               first=&a;
               last=&a;
               bignodelist.push_back(a);
            }else{
                if(!group[num]){
                    node b;
                    b.index=num;
                    b.prev=&last;
                    last.next=&b;
                    last=&b;
                }else{
                    node* insert=lastofgroup(group[num],*first);
                    node b;
                    b.index=num;
                    b.prev=insert;
                    b.next=*insert.next;
                    node* realnext=b.next;
                    insert->next=&b;
                    realnext->prev = &b;
                }
            }
        }
    }


}