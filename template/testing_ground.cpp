#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int s=300000;
    int f[s+1]={0};
    ll sum=0;
    for(int i=1;i<=500;i++){
        sum+=i*i*i;
    }
    cout<<sum<<endl;




    return 0;
}
