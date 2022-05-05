#include<bits/stdc++.h>//this is a LIS + LCS;
using namespace std;
struct store{
    int value;
    vector<int> arr;
};
inline pair<int,char> mymax(pair<int,char> &a,pair<int,char> &b,pair<int,char> &c){
    if(a>b){
        if(b>=c){
         return {a.first,2};
        }else {
            if(c>a) return {c.first,4};
            return {a.first,2};
        }
    }else{
        if(a>=c){
            return {b.first,3};
        }else{
            if(c>b) return {c.first,4};
            return {b.first,3};
        }
    }
}
int dx[4]={-1,-1,0,-1};
int dy[4]={-1,0,-1,-1};
int  main(){

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){

    int n;cin>>n;
    //LIS
    vector<int> ans1;
    vector<int> ans2;
    vector<store> s;
    for(int i=0;i<n;i++){
       int a;cin>>a;
       vector<int> temp;
       store tempstore;
       tempstore.value=a;
       tempstore.arr=temp;
       auto it = upper_bound(s.begin(),s.end(),tempstore,[](const store &a,const store &b){ return a.value>b.value ;});
       if(it!=s.end()){
           s[it-s.begin()]=tempstore;
           if(it-s.begin()){
               (s[it-s.begin()]).arr=(s[it-s.begin()-1]).arr;
           }
           ((s[it-s.begin()]).arr).push_back(a);
       }else{
           s.push_back(tempstore);
           if(s.size()!=1){
               (s[s.size()-1]).arr=(s[s.size()-2]).arr;
           }
           (s[s.size()-1].arr).push_back(a);
       }
        
    }
    ans1=s[s.size()-1].arr;

    for(int i=0;i<n;i++){
       int a;cin>>a;
       vector<int> temp;
       store tempstore;
       tempstore.value=a;
       tempstore.arr=temp;
       auto it = upper_bound(s.begin(),s.end(),tempstore,[](const store &a,const store &b){ return a.value>b.value ;});
       if(it!=s.end()){
           s[it-s.begin()]=tempstore;
           if(it-s.begin()){
               (s[it-s.begin()]).arr=(s[it-s.begin()-1]).arr;
           }
           ((s[it-s.begin()]).arr).push_back(a);
       }else{
           s.push_back(tempstore);
           if(s.size()!=1){
               (s[s.size()-1]).arr=(s[s.size()-2]).arr;
           }
           (s[s.size()-1].arr).push_back(a);
       }
        
    }
    ans2=s[s.size()-1].arr;
    
    //LCS
    pair<int,char> dp[ans1.size()+1][ans2.size()+1];
    for(int i=0;i<=ans1.size();i++){
        for(int j=0;j<=ans2.size();j++){
            if(i==0 || j==0){
                dp[i][j]={0,0};
            }else{
                if(ans1[i-1]==ans2[j-1]){
                    dp[i][j]={dp[i-1][j-1].first+1,1};
                }else{
                    dp[i][j] = mymax(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]);
                }
            }
        }
    }
    int x=ans1.size();int y=ans2.size();
    vector<int> realans;
    while(dp[x][y].first){
        if(dp[x][y].second==(char)1) realans.push_back(ans1[x-1]);
            int chari = dp[x][y].second;
            x+=dx[chari-1];
            y+=dy[chari-1];
    }
    for(auto i=realans.rbegin();i!=realans.rend();i++){
        cout << (*i) <<" \n"[next(i)==realans.rend()];
    }
    }
}
