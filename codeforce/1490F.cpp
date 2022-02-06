#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;
map<int,int> mpc;
int happentime(int target){
    int ans=0;
    for(auto i=mpc.begin();i!=mpc.end();++i){
       if(i->first<target){
           ans+=i->first*i->second;
       }
       if(i->first>target){
           ans+=((i->first)-target)*i->second;
       }
    }
    return ans;
}
int main(){
    int t;cin>>t;
    while(t--){
            int n;cin>>n;
    mp.clear();
    mpc.clear();
    int max=-1;
    for(int i=0;i<n;i++){
        int k;cin>>k;
        if(!mp.count(k)){
            mp[k]=1;
        }else{
            mp[k]=mp[k]+1;
        }
        if(mp[k]>max) max=mp[k];
    }
    for(auto i=mp.begin();i!=mp.end();++i){
        int k=i->second;
        if(!mpc.count(k)){
            mpc[k]=1;
        }else{
            mpc[k]=mpc[k]+1;
        }
    }
    int realans=n;
    if(max>mp.size()){
    for(auto i=mp.begin();i!=mp.end();++i){
        int j = happentime(i->second);
        if(j<realans) realans=j;
     }
    }else{
        for(int i=0;i<=max;++i){
        int j = happentime(i);
        if(j<realans) realans=j;
     } 
    }
    
  
    cout<<realans<<endl;
    //cout<<"\n";
    }

}