#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//greedy: if there is a dish of the same type in the pot, choose that ; if not choose the pot with the latest dish ;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k,p;cin>>n>>k>>p;
    int nextofi[p]; 
    int dish[p];
    set<int> s;//the pot;
    for(int i=0;i<p;i++){
        cin>>dish[i];
    }
    map<int,int> lastofn;
    for(int i=p-1;i>=0;i--){
        if(lastofn.count(dish[i])){
            nextofi[i]=lastofn[dish[i]];
            lastofn[dish[i]]=i;
        }else{
            nextofi[i]=1e9;
            lastofn[dish[i]]=i;
        }
    }
    int ans=0;
   for(int i=0;i<p;i++){
       if(s.count(i)){
           s.erase(i);
           s.insert(nextofi[i]);
       }else{
           if(s.size()<k){
              ans++;
              s.insert(nextofi[i]);
           }else{
               ans++;
               s.erase(prev(s.end()));
               s.insert(nextofi[i]);
           }
       }
   }
    cout<<ans<<endl;    

    return 0;
}