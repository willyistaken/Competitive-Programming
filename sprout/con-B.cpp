#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    int sum=0;
    vector<int> p(n+1,0);
    for(int i=0;i<n;i++){
        int a;cin>>a;
        sum+=a;
        p[i+1]=sum;
    }
    
    std::mt19937 generator(time(NULL));
    std::uniform_int_distribution<int> distribution(1,sum); 
    for(int i=0;i<m;i++){
        int j = distribution(generator);
        int it  = lower_bound(p.begin(),p.end(),j)-p.begin();
        cout<<it<<" \n"[i==m-1];
    }







    return 0;
}