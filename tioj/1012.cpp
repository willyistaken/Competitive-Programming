#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;cin>>n>>m;
    int waiting=0;int x=0;
     vector<int> station;
    for(int i=0;i<n;i++){  
        cin>>x;
        while(waiting<x){station.push_back(++waiting);}
        auto j = find(station.begin(),station.end(),x);
        int depth = station.end()-j;
        cout<<depth<<"|"<<station.size()<<"\\";
        if(depth<=m+1){
            station.erase(j);
        }else{
                cout<<"no"<<endl;
                return 0;
        }
    }
    
 
    cout<<"yes"<<endl;
    return 0;

}
