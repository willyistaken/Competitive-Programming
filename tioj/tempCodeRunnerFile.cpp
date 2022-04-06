#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        bool yes=0;
        string arr[2]={"yes\n","no\n"};
        for(int i=0;i<n/2;i++){
            if(i*i==n){
                yes=1;
                break;
            }
        }
        cout<<arr[yes];
    }
}