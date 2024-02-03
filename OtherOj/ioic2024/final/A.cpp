#include <iostream>
#include <cmath>
using namespace std;

using ll = long long;

ll dp[100010][25];
ll n, K, X;

ll A[100010], B[100010];

ll mysqrt(ll a){
    ll l=-1;ll r = 1e9+1;
    while(r-l>1){
        ll m = (l+r)/2;
        if(m*m>a) r = m;
        else l = m;
    }
    return l;
}

inline ll cal(ll a, ll b){
    if(a>b){
        return -mysqrt(a-b);
    }else{
        return mysqrt(b-a);
    }
}

int main() {
    cin >> n >> K >> X;
    
    for(int i=1; i<=n; i++) cin >> A[i];
    for(int i=1; i<=n; i++) cin >> B[i];
    
    dp[0][0] = X;
    for(ll i=1; i<=n; i++){
        dp[i][0] = dp[i-1][0] + cal(dp[i-1][0], A[i]);
        for(int k=1; k <= K; k++){
            dp[i][k] = max( dp[i-1][k] + cal(dp[i-1][k], A[i]), dp[i-1][k-1] + cal(dp[i-1][k-1], B[i]) );
        }
    }
    
    ll mx = -(1e18);
    for(int i=0; i<=K; i++) mx = max(mx, dp[n][i]);
    
    cout << mx << '\n';
    
    
    return 0;
}
