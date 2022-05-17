#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    multiset<int> s;
    while(cin>>n && n){
        if(n<0){
            if(s.size()){
            if(n==-1){
                cout<<*s.begin()<<" ";
                s.erase(s.begin());
            }
            else{
                cout<<*s.rbegin()<<" "; 
                s.erase(--s.end());   
            }  
            }  
        }else{
            s.insert(n);
        }
    }
    cout<<endl;






    return 0;
}