#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    int d;cin>>d;
    int total=0;
    int totaln=0;
    for(int i=0;i<n;i++){
        int sum=0;
        int maxi=INT_MIN;
        int mini=INT_MAX;
       
        for(int j=0;j<3;j++){
             int k;cin>>k;
            sum+=k;
            maxi = max(maxi,k);
            mini = min(mini,k); 
        }
        if(maxi-mini>=d){
            total+=sum/3;
            totaln+=1;
        }
    }
    cout<<totaln<<" "<<total<<endl;
}