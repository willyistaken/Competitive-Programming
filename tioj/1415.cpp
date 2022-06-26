#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int times[N]; 

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    while(cin>>n){
    fill(times,times+N,0);
    ll ans=0;
    priority_queue<int> ma;
    priority_queue<int,vector<int>,greater<int> > mi;
    for(int i=0;i<n;i++){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int k;cin>>k;
        ma.push(k);
        mi.push(k);
        times[k]++;
        

    }        
        while(!times[ma.top()]) ma.pop();
        while(!times[mi.top()]) mi.pop();
        ans += ma.top()-mi.top();
        times[ma.top()]--;times[mi.top()]--; 
    }
    cout<<ans<<"\n";
    }




    return 0;
}