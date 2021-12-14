#include <bits/stdc++.h>
using namespace std;

struct card{
    int index;
    char type;
    bool hoz;
};
//mpsz
map<char, int> tranmap = {
        {'m',0},
        {'p',1},
        {'s',2},
        {'z',3}
};
bool compare(card a,card b){
    if(tranmap[a.type]>tranmap[b.type]){
        return 0;
    }
    if(tranmap[a.type]<tranmap[b.type]){
        return 1;

    }
    if(a.index>b.index){
        return 0;
    }else{
        return 1;
    }
}
card arr[13];
stack<card> specialop;
void printarr(){
    for(int i=0;i<13;i++){
        if(arr[i]!=-1){
            cout<<arr[i].index;
        }
        
    }
    queue<char> temp;
    while(!specialop.empty()){
        if(specialop.top().hoz){
            cout<<"..";
            char t = '0'+specialop.top().index
            temp.push(specialop.top().index)
        }
    }
    cout<<endl;
       for(int i=0;i<13;i++){
        if(arr[i]!='o'){
            cout<<arr[i].type;
        }
        
    }
    cout<<endl;
    
}
void insert(int replacei,char replacec,int beingreplacei,char beingreplacec){
    for(int i=0;i<13;i++){
        if(arr[i].index==beingreplacei && arr[i].type==beingreplacec){
            arr[i].index=replacei;
            arr[i].type=replacec;
            return ;
        }
    }

}
int main(){
    int T;cin>>T;
    for(int m=0;m<T;m++){
    for(int i=0;i<13;i++){
        string a;
        cin>>a;
        card b;
        b.index=a[0]-'0';
        b.type = a[1];
        b.hoz=false;
        arr[i]=b;
    }
    sort(arr,arr+13,compare);
    printarr();
    int q;cin>>q;
    for (int i=0;i<q;i++){
        string action;cin>>action;
        string a;cin>>a;
        string throwout;cin>>throwout;
        string b;cin>>b;
        insert(a[0]-'0',a[1],b[0]-'0',b[1]);
        sort(arr,arr+13,compare);
        printarr();
    }
    
    
    
}
return 0;
}