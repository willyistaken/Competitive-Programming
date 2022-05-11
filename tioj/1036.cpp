#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long;
//this linear sieve doesn't work i believe, because of the time and memory constrant
/*
int main(){ 
    int m;cin>>m;
    int n=10000000;
    vector<int> p;
    vector<int> arr(n+1,0);
    vector<int> ans(n+1,0);;
    int c=0;
    for(int i=2;i<=n;i++){
        if(!arr[i]){
            arr[i]=i;
            p.push_back(i);
            ++c;
        }
        for(auto k:p){
            if(!(k>arr[i]||i*k>n)){
            arr[i*k]=k;
            }else{
             break;
            }
        }
        ans[i]=c;
    }

    while(m--){
        int q;cin>>q;
        cout<<ans[q]<<"\n";
    }
    return 0;
}
*/
int main(){ 
    int m;cin>>m;
    int n=10000000;
    vector<bool> arr(n+1,0);
    vector<int> ans(n+1,0);;
    int c=0;
    for(int i=2;i<=n;i++){
        if(!arr[i]){
            int j=2;
            while(i*j<=n){
                arr[j*i]=1;
                j++;
            }
            ++c;
        }
        ans[i]=c;
    }

    while(m--){
        int q;cin>>q;
        cout<<ans[q]<<"\n";
    }
    return 0;
}
