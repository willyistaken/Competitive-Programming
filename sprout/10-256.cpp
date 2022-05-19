#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
int dp[1<<24];
int n;
//fk long long;

tuple<__int128_t,__int128_t,__int128_t> coeff(long long x1,long long y1,long long x2,long long y2){
    __int128_t bottom = (__int128_t)x1*x2*(x1-x2); 
    __int128_t top =  ((__int128_t)x2*y1) - (x1*y2);
    __int128_t btop = ((__int128_t)y1*(x2*(x1-x2))) - (((__int128_t)x1*x2*y1)-((__int128_t)x1*x1*y2));
    return {top,btop,bottom};
}

int solve(int s,vector<pair<long long,long long> > &ps){
    if(dp[s]) return dp[s];
    if(s==0) return 0;
    if(s-(s&-s)==0) return 1;
    int source = __lg(s&-s);
    int minn=INT_MAX;
    for(int i=source+1;i<n;i++){
        int g=s-(s&-s);
        if((s>>i)&1){
            tuple<__int128_t,__int128_t,__int128_t> co = coeff(ps[source].first,ps[source].second,ps[i].first,ps[i].second);
            if(get<0>(co)*get<2>(co)<0){
                g-=1<<i;
                for(int j=0;j<n;j++){
                    if((g>>j)&1){
                        if((get<0>(co)*ps[j].first*ps[j].first) + (get<1>(co)*ps[j].first) == get<2>(co)*ps[j].second){
                            g-=1<<j;
                        }      
                    }
                }
                minn = min(minn,solve(g,ps)+1);
            }
        }
    }
    minn = min(minn,solve((s-(s&-s)),ps)+1);
    dp[s]=minn;
    return dp[s];
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
    fill(dp,dp+(1<<24),0);
    cin>>n;
    vector<pair<long long,long long> > ps;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b; 
        ps.push_back({(long long)a,(long long)b});
    }
    cout<<solve((1<<n)-1,ps)<<endl;
    }
    return 0;
}