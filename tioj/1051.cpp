#include<bits/stdc++.h>
using namespace std;
struct store{
    int value;
    vector<int> arr;
};
bool compa(store a,store b){
    return a.value<b.value;
}
int  main(){

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    vector<int> ans1;
    vector<int> ans2;
    vector<store> s;
    for(int i=0;i<n;i++){
       int a;cin>>a;
       vector<int> temp;
       store tempstore;
       tempstore.value=a;
       tempstore.arr=temp;
       auto it = upper_bound(s.begin(),s.end(),tempstore,compa);
       if(it!=s.end()){
           s[it-s.begin()]=tempstore;
       }else{
           s.push_back(tempstore);
       }
       it--;
       if(it!=s.begin()){
           s[it-s.begin()+1].arr=s[it-s.begin()].arr;

       }
       (s[it-s.begin()+1].arr).push_back(a);
        
    }
    ans1=(*(s.end())).arr;
    for(auto i : ans1){
        cout<<i;
    }
   // for(int i=0;i<n;i++){
     //   cin>>arr2[i];
    //}


}