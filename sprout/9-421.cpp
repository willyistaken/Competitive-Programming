#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){

    int n,m;cin>>n>>m;
    vector<int> sog;
    vector<int> s1;
    vector<int> s2;
    for(int i=0;i<n;i++){
        s1=sog;
        s2=sog;
        int a;cin>>a;
        int ind=-1;
        if(a>=m) {
        auto it = upper_bound(s1.begin(),s1.end(),a);
        ind = it-s1.begin();
        if(it!=s1.end()) s1[ind] = a;
        else s1.push_back(a);
        }
        if(2*a>=m){
            auto it = upper_bound(s2.begin(),s2.end(),2*a);
            ind = it-s2.begin();
            if(it!=s2.end()) s2[ind] = 2*a;
            else s2.push_back(2*a);
        }
        if(s1.size()>s2.size()) sog=s1;
        if(s1.size()<s2.size()) sog=s2;
        if(s1.size()==s2.size()) sog=min(s1,s2);
    }
    cout<<max(s1.size(),s2.size())<<endl;

    }





    return 0;
}