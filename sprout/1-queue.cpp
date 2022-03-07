#include <bits/stdc++.h>
using namespace std;


int main(){
    queue<int> astack;
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int c;cin>>c;
        if(c==1){
            int n;cin>>n;
            astack.push(n);
        }else{
            if(astack.empty()){
                cout<<"empty!"<<endl;
            }else{
                cout<<astack.front()<<endl;
                astack.pop();
            }
        }
    }
}