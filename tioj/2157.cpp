#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    ll arr[n];
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    ll power = 1LL;
    for (int i = 0; i < n; i++) {
        sum += (power)*arr[i] % MOD;
        sum = (sum > MOD) ? sum - MOD : sum;
        power <<= 1;
        power%=MOD;
    }

    cout << sum << endl;

    return 0;
}