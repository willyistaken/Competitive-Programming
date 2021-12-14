#include <bits/stdc++.h>
using namespace std;

struct card{
    int index;
    char type;
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

int main(){
    int T;cin>>T;
    for(int m=0;m<T;m++){
      card arr[13];
    for(int i=0;i<13;i++){
        string a;
        cin>>a;
        card b;
        b.index=a[0]-'0';
        b.type = a[1];
        arr[i]=b;
    }
    int q;cin>>q;
    if(q!=0){
        return 0;
    }
    sort(arr,arr+13,compare);
    for(int i=0;i<13;i++){
        cout<<arr[i].index;
    }
    cout<<endl;
       for(int i=0;i<13;i++){
        cout<<arr[i].type;
    }
    cout<<endl;
    }
    return 0;
}