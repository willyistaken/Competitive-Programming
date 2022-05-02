#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long;
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string l1,l2;cin>>l1>>l2;
    int maxn=0;
    int l1s=l1.size();
    int l2s=l2.size();
    for(int i=-l2s+1;i<=l1s-1;i++){
        int count=0;
        for(int j=0;j<l1s;j++){
               count+= (j+i>=0 && j+i<l2s) ? (l1[j]==l2[j+i]):0;
        }
        maxn=max(maxn,count);
    }
    cout<<maxn<<"\n";
    return 0;
}

//據說這題常數夠小可這樣做，但正解是FFT
//FFT解:




//to be continue;
