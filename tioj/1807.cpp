#include <bits/stdc++.h>
using namespace std;

int main(){
    int m,n;cin>>m>>n;
    map<string , bool> edge;
    int a,b;
    while(n--){
        cin>>a>>b;
        if(a==b ){
            cout<<"Yes"<<endl;
            return 0;
        }
        
        if(b>a) swap(a,b);
        string nestring = to_string(a)+","+to_string(b);
        if(edge.count(nestring)){
            cout<<"Yes"<<endl;
            return 0;
        }
        edge.insert(make_pair(nestring,1));
    }
    cout<<"yes"<<endl;
    return 0;
}