#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;cin>>n>>q;
    vector<int> b(n);
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>b[i];
        sum+=b[i];
    }
    int now=0;
    bitset<200000> s;
    s.reset();
    for(int i=0;i<q;i++){
        short type;cin>>type;
        if(type==1){
            int f,t;cin>>f>>t;
            if(s[f-1]){
                sum-=now;
                s[f-1]=0;
            }else{
              sum-=b[f-1];  
            }
            sum+=t;
            b[f-1]=t;
        }else{
            int j;cin>>j;
            now=j;
            sum=1LL*n*j;
            s.set();
        }
        cout<<sum<<endl;
    }





    return 0;
}