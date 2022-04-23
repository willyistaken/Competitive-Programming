#include <bits/stdc++.h>
using namespace std;
int k,q;
int size;
bool reversed=0;
struct node{
    int val;
    int connect[2];
};
int alreadymod=-1;
int mid=-1;
bool addmid=0;
vector<node> store; 
void add(int n,int &head,int &tail){
    size++;  
    node tempnew;
    tempnew.val=n; 
    if(size==1){ 
        tempnew.connect[0]=-1;
        tempnew.connect[1]=-1;
        store.push_back(tempnew);
        head =store.size()-1;
        tail=store.size()-1;
        mid=head;
        addmid=0;
        return;
    }
    addmid=!addmid;
    if(reversed){
        tempnew.connect[0]=-1;
        tempnew.connect[1]=head;
        store[head].connect[0]=store.size();
        store.push_back(tempnew);
        head = store.size()-1;
        if(addmid) mid = store[mid].connect[0];
    }else{
        tempnew.connect[1]=-1;
        tempnew.connect[0]=tail; 
        store[tail].connect[1]=store.size();
        store.push_back(tempnew);
        tail = store.size()-1;
        if(addmid) mid = store[mid].connect[1];
    }
   
   
}
//remember to do stuff
void myremove(int &tail,int &head){
    if(size==0) return;
    if(size==1){
        head=-1;
        tail=-1;
        size=0;
        mid=-1;
        return;
    }
    node now = store[mid];
    store[now.connect[0]].connect[1]=now.connect[1];
    store[now.connect[1]].connect[0]=now.connect[0];
    mid = now.conect[reversed];
    size--;
}

void mod(int &head,int &tail){
    return;
    alreadymod+=1;
    for(int  i=alreadymod;i<=max(head,tail);i++){
        store[i].val%=k;
    }
    alreadymod = max(head,tail);
    
}
void myreverse(){
    if(size%2==0){

    }
    reversed=!reversed;

}
void printout(int &head,int &tail){
    if(size==0){
        cout<<endl;
        return;
    }
    if(!reversed){
        node now = store[head];
        while(now.connect[1]!=-1){
            cout<<now.val<<" ";
            now = store[now.connect[1]];
        }
        cout<<now.val<<endl;
    }else{
        node now = store[tail];
        while(now.connect[0]!=-1){
            cout<<now.val<<" ";
            now = store[now.connect[0]];
        }
        cout<<now.val<<endl;
    }   
}
  
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>k>>q;
    int head=-1;
    int tail=-1;
    string ask[q];
    queue<int> addnumber;
    int lastmod=-1;
    for(int i=0;i<q;i++){
        cin>>ask[i];
        if(ask[i]=="Add"){
            int a;cin>>a;
            addnumber.push(a);
        }
        if(ask[i]=="Mod"){
            lastmod=i;
        }
    }
    for(int i=0;i<q;i++){

        string qe=ask[i];
        if(qe=="Add"){
            int n=addnumber.front();
            addnumber.pop();
            if(i<=lastmod) n%=k;
            add(n,head,tail);
        }
        if(qe=="Reverse"){
            myreverse();
        }
        if(qe=="Remove"){
            myremove(tail,head);
        }
        if(qe=="Mod"){
            mod(head,tail);
        }
    }
    
    printout(head,tail);


}