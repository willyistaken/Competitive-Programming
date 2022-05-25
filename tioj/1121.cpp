#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Icantname{
    deque<char> arr;
    int ind;
};
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    while(cin>>n){
    string temp;cin>>temp;
    deque<char> s;
    for(int i=0;i<n;i++) s.emplace_back(temp[i]);
    vector<Icantname> a;
    for(int i=0;i<n;i++){
        a.push_back({s,i+1});
        s.emplace_back(s[0]);
        s.pop_front();
    }


    sort(a.begin(),a.end(),[](const Icantname &x,const Icantname &y){return x.arr<y.arr;});
    int ans2=0;
    for(int i=0;i<n;i++){
        cout<<(a[i].arr).back();
        if(a[i].ind==2) ans2 = i+1;
    }
    cout<<endl<<ans2<<endl;
    }




    return 0;
}