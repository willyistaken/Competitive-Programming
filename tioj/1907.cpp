#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct doll{
    int w;
    int h;
};
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
    int m;cin>>m;
    doll arr[m];
    for(int i=0;i<m;i++){
        cin>>arr[i].w>>arr[i].h;
    }
    sort(arr,arr+m,[](const doll &a,const doll &b){return (a.w<b.w || (a.w==b.w && a.h>b.h));});
    multiset<int> s;
    for(int i=0;i<m;i++){
        s.insert(arr[i].h);
        auto it = s.lower_bound(arr[i].h);
        it++;
        if(it!=s.end()) s.erase(it);
    }
    cout<<s.size()<<endl;
    }
//note to self:remember this  if has duplicates: multiset    if stricly increasing: it = lowerbound && it++


    return 0;
}
