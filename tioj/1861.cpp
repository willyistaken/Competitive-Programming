#include <bits/stdc++.h>
using namespace std;
long long  v[100000];
int main(){
     ios_base::sync_with_stdio(0), cin.tie(0);
    long long n,ans;
    while(cin>>n){
        ans=0;
        
        for(long long  i=0;i<n;i++){
            cin>>v[i];
            }
        priority_queue<long long,vector<long long>,greater<long long> > pirorq(v,v+n);
        while(pirorq.size()>1){
            long long  x = pirorq.top();
            pirorq.pop();
            long long  y = pirorq.top();
            pirorq.pop();
            ans+=x+y;
            pirorq.push(x+y);
        }
        cout<<ans<<endl;

    }
}
