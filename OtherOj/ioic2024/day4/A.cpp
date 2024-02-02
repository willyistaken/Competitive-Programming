#include <iostream>
using namespace std;

using ll = long long;

ll n, m, a, c;
ll d[1010];

ll M[1010], ans[1010], sum;

int main() {
    cin >> n >> m >> a >> c;
    
    for(int i=1; i<=n; i++){
        cin >> d[i];
        M[i] = m;
    }
    
    for(int i=1; i<=n; i++){
        ans[i] = min(M[i], d[i]);
        d[i] -= ans[i];
        M[i] -= ans[i];
        if(!d[i]) continue;
        
        for(int k=i-1; k>0 && d[i]; k--){
            if( (i-k)*a > c ) break;
            
            if( M[k] ){
                ll t = min(d[i], M[k]);
                    
                sum += a * (i-k) * t;
                ans[k] += t;
                M[k] -= t;
                d[i] -=t;
            }
            
        }
        
        sum += d[i] * c;
        ans[i] += d[i];
        d[i] = 0;
    }
    
    cout << sum << '\n';
    for(int i=1; i<=n; i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}
