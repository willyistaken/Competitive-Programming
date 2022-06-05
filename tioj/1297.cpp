#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
   while(cin>>n){
       if(n<0) {
           cout<<"stupid\n";
           continue;
       }
       for(int i=0;i<n;i++){
           if(i == ((n-i)/100)){
               if(n-i>1024 || n-i<0){
                   cout<<"stupid\n";
               }else{
                   cout<<n-i<<endl;
               }
               break;
           }
       }
   } 







    return 0;
}