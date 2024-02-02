#include<bits/stdc++.h>
using namespace std;
 
void solve(){
    string s;cin>>s;
    int n = s.size();
    int cnt = 0;
    int head = 0;
    for(int i=1;i<n;i++){
        if(s[i]==s[i-1]) {
            cnt++;
            if(s[i]==s[head] && i-head>1) cnt++;
            head = i;
        }
    }
    cnt++;
    if(s[n-1]==s[head] && n-1-head>1) cnt++;
    cout<<cnt<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--){
        solve();
    }
}
 
 
