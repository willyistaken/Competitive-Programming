#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[1<<24];
int n;
//fk long long;

tuple<ll,ll,ll> coeff(int x1,int y1,int x2,int y2){
    ll bottom = 1LL*x1*x2*(x1-x2); 
    ll top =  (1LL*x2*y1) - (1LL*x1*y2);
    ll btop = (1LL*y1*(x2*(x1-x2))) - ((1LL*x1*x2*y1)-(1LL*x1*x1*y2));
    return {top,btop,bottom};
}

int solve(int s,vector<pair<int,int> > &ps){
    if(dp[s]) return dp[s];
    if(s==0) return 0;
    if(s-(s&-s)==0) return 1;
    int source = __lg(s&-s);
    int minn=INT_MAX;
    for(int i=source+1;i<n;i++){
        int g=s-(s&-s);
        if((s>>i)&1){
            tuple<ll,ll,ll> co = coeff(ps[source].first,ps[source].second,ps[i].first,ps[i].second);
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
    vector<pair<int,int> > ps;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b; 
        ps.push_back({a,b});
    }
    cout<<solve((1<<n)-1,ps)<<endl;
    }
    return 0;
}





/*
2
7
1 3
2 4
3 3
2 6
4 8
1 1
1 2
6
1 8
2 12
3 12
4 4
5 5
6 6
*/