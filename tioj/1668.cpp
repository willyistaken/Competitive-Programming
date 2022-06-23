#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =66000;
vector<int> prime;
void init(){
    bool notprime[N+1]={0};
    notprime[0]=1;
    notprime[1]=1;
    for(int i=2;i<=N;i++){
        if(!notprime[i]){
            prime.push_back(i);
            for(int j=2;j*i<=N;j++){
                notprime[j*i]=1;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int l,r;cin>>l>>r;
        int ans=0;
        int notprime[r-l+1]={0};
        for(auto i : prime){
            if(i>r) break;
            int m = max((l/i + (l%i!=0)),2);
            for(;m*i<=r;m++){
                notprime[m*i-l]=1;
            }
        } 
        for(int i=0;i<=r-l;i++){
            if(!notprime[i]) ans++;
        }   
        cout<<ans<<endl;
    }







    return 0;
}

//sieve in a interval