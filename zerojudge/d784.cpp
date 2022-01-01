#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int allmax=0;
        cin>>allmax;
        int sum=allmax;
        for(int i=0;i<n-1;i++){
            int m;cin>>m;
            sum+=m;     
            if(sum>=allmax){
                allmax=sum;
            }else{
               if(sum<0){
                sum=0;
            } 
            }
      
        }
            
          
         
        cout<<allmax<<endl;
    }
}