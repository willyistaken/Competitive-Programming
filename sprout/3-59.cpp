#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    priority_queue<int,vector<int>,greater<int> > q;
    while(t--){
        int ty;cin>>ty;
        if(ty-1){
            if(q.empty()){
                cout<<"empty!\n";
            }else{
                cout<<q.top()<<endl;
                q.pop();
            }
        }else{
            int n;cin>>n;
            q.push(n);
        }
    }
}