#include <iostream>
using namespace std;

using ll = long long;
ll MOD = 998244353;

ll dp[3000010];
ll t, n;

int main() {
    
    ll a, b;
    a = b = 1;
    
    dp[0] = dp[1] = 1;
    for(int i=2; i<3000005; i++){
        b = a + b;
        a = (MOD +b - a);
        
        a %= MOD;
        b %= MOD;
        
        
        dp[i] = b % MOD;
    }
    
    
    cin >> t;
    while(t--){
        cin >> n;
        
        cout << dp[2*n -1] << '\n';
    }
    
    return 0;
}
