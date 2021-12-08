#include <bits/stdc++.h>
using namespace std;


bool sameforn(string a,string b,int n){
    if(a.substr(0,n)==b.substr(b.size()-n,n)){
        return true;
    }else{
        return false;
    }
}




int main(){
    string a,b;cin>>a>>b;
    //a="example";b="exam";
    int ans=0;
    for(int i=0;i<=min(a.size(),b.size());i++){
        if(sameforn(a,b,i))ans=i;
    }
    cout<<ans;
}