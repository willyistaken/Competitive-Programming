#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin>>n,n){
        int sum=0;
        for(int i=0;i<n;i++){
            int a,b;cin>>a>>b;
            sum+=(min(a,b));
        }
        cout<<sum<<endl;
    }
}