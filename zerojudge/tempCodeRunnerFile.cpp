#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int max=0;
        int min=0;
        int sum=0;
        for(int i=0;i<n;i++){
            int m;cin>>m;
            sum+=m;
            if(sum>max){
                max=sum;
            }
            if(sum<min){
                min=sum;
            }
        }
        cout<<max-min<<endl;
    }
}