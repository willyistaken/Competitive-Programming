#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    while(cin>>n){
    set<ll> s;
    for(int i=0;i<n;i++){
        int temp;cin>>temp;
        if(temp>0){
            s.insert(1LL*temp*temp);
        }
    }
    auto i = s.begin();
    int ans=0;
    while(i!=s.end()){
       auto j=next(i);
        while(j!=s.end()){
            ans+=s.count(*i+*j);
            ++j;
        }
        ++i;
    }
    cout<<ans<<endl;
    }
    return 0;
}
