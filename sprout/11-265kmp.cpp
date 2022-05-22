//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long;
vector<int> kmp(500007,0);
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    
    string a;cin>>a;
    string s;cin>>s;
    queue<int> ans;
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
        int head=0;
        for(int k=0;k<s.size();++k){
            if(s[k]==a[head]){
                ++head;
            }else{
                head=kmp[head];
                k--;
                if(head==-1){
                    k++;
                    head=0;
                }
            } 
            if(head==a.size()) {
                ans.push(k-a.size()+1);
                head=kmp[head]; 
            }
        }
        while(!ans.empty()){
            cout<<ans.front();
            if(ans.size()>1) cout<<" ";
            ans.pop();
        } 
        cout<<endl;







    return 0;
}