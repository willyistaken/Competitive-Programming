//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int eval(string s){
    if(s[2]==s[3]&&s[3]==s[4]&&s[4]==s[5]) return 2000;
    if(s[2]==s[3] && s[4]==s[5]) return 1500;
    return 1000;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
     int n;cin>>n;
     ll ans=0;
     for(int i=0;i<n;i++){
         string s;cin>>s;
        ans+=eval(s);
     }
    cout<<ans<<endl;






    return 0;
}