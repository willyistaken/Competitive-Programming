#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        bool haszero=0;
        bool allzero=1;
        int n;cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            int k;cin>>k;
            if(k) allzero=0;
            else haszero=1;
            arr[i]=k;
        }
        int con=0;
        for(int i=0;i<n;i++){
            if(arr[i]){
                con+=1;
                while(arr[i] && i<n){arr[i]=0;i++;}
            }
        }

        if(allzero) {
            cout<<0<<endl;
            continue;
        }else if(!haszero || con==1){
            cout<<1<<endl;
            continue;
        }else{
            cout<<2<<endl;
        }
        
    }


    return 0;
}