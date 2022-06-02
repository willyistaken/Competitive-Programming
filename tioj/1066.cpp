#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long;
int v[5]={1,5,10,20,50};
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
     int c;cin>>c;
    int need=0;
    int arr[5];
    for(int i=0;i<5;i++){
        int temp;cin>>temp;
        arr[i]=temp;
        need+=temp*v[i];
    }
    need-=c;   
    for(int i=0;i<5;i++){
        int temp;cin>>temp;
        arr[i]+=temp;
    }
    int ans=0;
    for(int i=4;i>=0;i--){
        if(need>(arr[i]*v[i])){
            ans+=arr[i];
            need-=arr[i]*v[i];
        }else{
            ans+=need/v[i];
            need%=v[i];
        }
    }
    cout<<ans<<endl;
    }
    return 0;
}
	
