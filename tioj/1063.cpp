#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    bool arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int cur[m]={0};
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cur[j]=arr[i][j] ? cur[j]+1 : 0; 
        } 
       
        int left[m]={0};
        int right[m]={m-1};
        stack<int> mono;
        mono.push(0);
        for(int j=1;j<m;j++){
            while(!mono.empty()){
                if(cur[mono.top()]<cur[j]) break;
                mono.pop();
            }
            if(mono.empty()){
                left[j]=0;
            }else{
                left[j]=mono.top()+ 1;
            }
            mono.push(j);
        }
        while(!mono.empty()) mono.pop();
        mono.push(m-1);
        for(int j=m-2;j>=0;j--){
            while(!mono.empty()){
                if(cur[mono.top()]<cur[j]) break;
                mono.pop();
            }
            if(mono.empty()){
                right[j]=m-1;
            }else{
                right[j]=mono.top()-1;
            }
            mono.push(j);
        }
        for(int j=0;j<m;j++){
            ans = max(ans,cur[j]*(right[j]-left[j]+1));
        }
    }
    cout<<ans<<endl;







    return 0;
}