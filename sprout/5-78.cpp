#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){

    int arr[7];
    for(int i=0;i<6;i++){
        cin>>arr[i+1];
    }
    int ans=0;
    ans+=arr[6];
    ans+=arr[5];
    arr[1]-=11*arr[5];
    ans+=arr[4];
    arr[2]-=5*arr[4];
    ans+=(arr[3]/4);
    arr[3]=arr[3]%4;
    if(arr[3]>0){
        ans+=1;
        if(arr[3]==1){
            arr[2]-=5;
            arr[1]-=7;
        }
        if(arr[3]==2){
            arr[2]-=3;
            arr[1]-=6;
        }
        if(arr[3]==3){
            arr[2]-=1;
            arr[1]-=5;
        }
    }
    if(arr[2]>0){
        ans+=arr[2]/9; 
        if(arr[2]%9) ans++;
        arr[1]-=(36-(arr[2]%9)*4);
    }else{
        arr[1]-=(-arr[2])*4;
    }
    if(arr[1]>0){
         ans+=(arr[1]/36); 
         if(arr[1]%36) ans++;
    }
    cout<<ans<<endl;
    }
}