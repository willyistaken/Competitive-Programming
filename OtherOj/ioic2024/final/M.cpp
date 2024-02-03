#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
#define int long long 
#define sz(x) (int)(x.size())
#define F first  
#define S second  
#define pb(x) emplace_back(x)

int n, l, k;

void solve(){
    string s;
    cin >> s;
    if(k == 1) cout << l << "\n";
    else if(l == k){
        int ans = 0;
        for(int i=0; i<l/2; i++){
            if(s[i] != s[l-i-1]) ans ++;
        }
        cout << l - ans << '\n';
    }else{
        int ans = 0;
        if(k % 2){
            int all = 0, ma = 0;
            vector<int> cnt(26);
            for(int i=0; i<l; i+=2){
                cnt[s[i] - 'a'] ++;
                ma = max(ma, cnt[s[i] - 'a']);
                all ++;
            }
            ans += all - ma;
			fill(cnt.begin(),cnt.end(),0);
            all = 0, ma = 0;
            for(int i=1; i<l; i+=2){
                cnt[s[i] - 'a'] ++;
                ma = max(ma, cnt[s[i] - 'a']);
                all ++;
            }
            ans += all - ma;
        }else{
            int all = 0, ma = 0;
            vector<int> cnt(26);
            for(int i=0; i<l; i++){
                cnt[s[i] - 'a'] ++;
                ma = max(ma, cnt[s[i] - 'a']);
                all ++;
            }
            ans += all - ma;
        }
        cout << l - ans << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> l >> k;
    while(n --) solve();
    return 0;
}
