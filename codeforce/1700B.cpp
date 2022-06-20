#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        if(s[0]!='9'){
        for(auto i : s){
            cout<<(9-(i-'0'));
        }
        cout<<endl;
        }else{
            stack<char> ans;
            int carry=0;
            for(int i = n-1;i>=0;i--){
                int trued = (s[i]-'0')+carry;
                if(trued<=1){
                    ans.push(('0'+(1-trued)));
                    carry=0;
                }else if(trued==10){
                    ans.push('1');
                    carry=1;
                }else{
                    ans.push('0'+(11-trued));
                    carry=1;
                }
            }
            while(!ans.empty()){
                cout<<ans.top();
                ans.pop();
            }
            cout<<endl;
        }
    }







    return 0;
}