#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    priority_queue<int,vector<int>,greater<int> > s;
    int ans=0;
    for(int i=0;i<n;i++){
        int t;cin>>t;
        if(s.size()<m){
            s.push(t);
            ans = max(ans,t);
        }else{
            int k = s.top();
            s.pop();
            k+=t;
            s.push(k);
            ans=max(k,ans);
        }
    }
    cout<<ans<<endl;







    return 0;
}