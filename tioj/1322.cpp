#include <bits/stdc++.h>
using namespace std;
#define ll long long;
// 性質: 一個二元搜尋樹如果包含元素的插入順序，這個樹就會變成treap(插入順序為heap)，而且插入時的父親只會是這個離這個元素最近的元素
//note to self: map is just set but paired and hashed;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    map<int,int> s;
    int n;cin>>n;
    int ans[n+1];
    s.insert({0,-1});
    s.insert({n+1,-1e9});
    int r;
    for(int i=0;i<n;i++){
        cin>>r;
        auto it=s.lower_bound(r);
        auto it2=it;
        it2--;
//  note to self: originally the above 3 lines looks like this:
/*      auto it = s.lower_bound(r);
        auto it2=it--;
*/
//which is correct but gets TLE　on tioj , because of the way iter-- is implemented, this way of writing code has major performance impact(in this case)
// see https://stackoverflow.com/questions/24901/is-there-a-performance-difference-between-i-and-i-in-c
        if(it2->second > it->second){
            ans[r]=it2->first;
        }else{
            ans[r]=it->first;
        }
        s.insert({r,i});
    }

    for(int i=1;i<=n;i++){
        cout<<ans[i]<<"\n";
    }





}