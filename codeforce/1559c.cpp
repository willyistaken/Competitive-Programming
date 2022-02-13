#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
    bitset<10005> road;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        if(k){
          road.set(i) ;
        }
    }
    if(road.test(0)){
        cout<<n+1;
        for(int i=1;i<=n;i++){
            cout<<" "<<i;
        }
        cout<<endl;
    }else if(!road.test(n-1)){
        for(int i=1;i<=n+1;i++){
            cout<<i<<" ";
        }
        cout<<endl;
    }else{
        bool yes=0;
        for(int i=0;i<n-1;i++){
            if(!road.test(i) && road.test(i+1) && !yes){
                for(int j=1;j<=i+1;j++){
                    cout<<j<<" ";
                }
                cout<<n+1<<" ";
                for(int j=i+2;j<=n;j++){
                    cout<<j<<" ";
                }
                cout<<endl;
                yes=1;
                break;
            }
        }
        if(!yes){
            cout<<-1<<endl;
        }
    }
    }
    
}