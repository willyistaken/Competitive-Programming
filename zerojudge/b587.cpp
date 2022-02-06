#include <bits/stdc++.h>
using namespace std;
long long ans[31]={0};
int main(){
    ans[0]=1;
    ans[1]=0;
    ans[2]=3;
    long long sum=4;//ans[2]+ans[0] (ans[0] is 1)
    for(int i=3;i<=30;i++){
        if(i%2==1){
            ans[i]=0;
            continue;
        }
        
        ans[i]=ans[i-2]+(2*sum);
        sum+=ans[i];
    
    }
    int n;
    while(cin>>n&&n>=0){
        cout<<ans[n]<<endl;
    }
}