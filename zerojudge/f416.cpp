//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long;
vector<int> kmp(10005,0);
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    
    int n;cin>>n; 
    string a;cin>>a;
    string s;cin>>s;
        fill(kmp.begin(),kmp.end(),0);
        kmp[0]=-1;
        for(int j=1;j<=a.size();j++){
            int cur=kmp[j-1];
            while(cur>=0){
                if(a[j-1]==a[cur]){
                    kmp[j]=cur+1;
                    break;
                }else{
                    cur=kmp[cur];
                }
            }
            if(cur<0){
                kmp[j]=0;
            }
        }
        int ans=0; 
        int head=0;
        for(int k=0;k<s.size();++k){
            if(s[k]==a[head]){
                ++head;
            }else{
                head=max(kmp[head],0); 
            } 
            if(head==a.size()) {
                ++ans;
                head=kmp[head]; 
            }
        }
        cout<<vector<string>{"NO","YES"}[ans==n]<<"\n";   








    return 0;
}