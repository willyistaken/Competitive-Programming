#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;cin>>t;
    while(t--){
       int arr[10]={0};
    long long n;cin>>n;
    if(n==1) arr[1]+=1;
    bool possible =1;
    while(n>1){
        int anything = 0;
        for(int i=9;i>=2;i--){
            if(n%i==0){
                arr[i]+=1;
                anything =1;
                n/=i;
                break;
            }
        }
        if(!anything){
            possible =0;
            break;
        }
    }
    if(possible){
        string c="";
        for(int i=1;i<=9;i++){
            while(arr[i]>0){
                c+=to_string(i);
                arr[i]-=1;
            }
        }
        cout<<c<<endl;
    }else{
        cout<<-1<<endl;
    } 
    }
    
    
}