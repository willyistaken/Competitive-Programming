//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int g;
    vector<int> arr;
    while(cin>>g){
    int n=1;
    arr.clear();
    arr.push_back(g);
    if(g==0){
        cout<<100<<endl;
        continue;
    }
    while(cin>>g && g){
        arr.push_back(g);
        n++;
    }
    n+=1;
    ll dp[n]={0};
    for(int i=1;i<n;i++){
        ll minn=LONG_LONG_MAX;
        for(int j=i-1;j>=max(i-3,0);j--){
            minn = min(dp[j],minn);
        }
        dp[i]=minn+arr[i-1];
    }
    ll minn=LONG_LONG_MAX;
    for(int i=n-1;i>=max(n-3,0);i--){
        minn = min(dp[i],minn);
    }
    cout<<(1LL*minn+(10LL*n))*10LL<<endl;
    }




    return 0;
}