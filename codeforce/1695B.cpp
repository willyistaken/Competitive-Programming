#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int arr[n];
        int minn= INT_MAX;
        int loc=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            loc = (minn>arr[i]) ? i:loc;
            minn = min(arr[i],minn);
        }
        if(n%2){
            cout<<"Mike\n";
        }else{
            if(loc%2){
                cout<<"Mike\n";
            }else{
                cout<<"Joe\n";
            }
        }





    }
    return 0;
}