#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(x,a,b) for(int x=a;x<=b;x++)
#define pb emplace_back
#define F first
#define S second

const int MAX = 1e6;
const int SIZE = 5e5 + 5;

bool isp[MAX + 5];
int phi[MAX + 5];
vector<int> prime;

void sieve() {
    isp[1] = phi[1] = 1;
    FOR (i, 2, MAX) {
        if (!isp[i]) {
            prime.pb (i);
            phi[i] = i - 1;
        }
        for (int p : prime) {
            int t = i * p;
            if (t > MAX)
                break;
            isp[t] = 1;
            if (i % p == 0) {
                phi[t] = phi[i] * p;
                break;
            } else
                phi[t] = phi[i] * (p - 1);
        }
    }
}

int n, k, a[SIZE];

int power (int d, int up, int mod) {
    int ans = 1;
    while (up) {
        if (up & 1)
            ans = ans * d % mod;
        d = d * d % mod;
        up >>= 1;
    }
    return ans;
}

tuple<int, int, int> len (int x, int mod) {
    int last = 1, now;
    for (int i = 1;; i++) {
        now = last * x % mod;
        if (__gcd (now, mod) == __gcd (last, mod))
            return {__gcd (now, mod), last, i - 1};
        last = now;
    }
}

int brute (int i) {
    if (i == n)
        return a[i];
    return power (a[i], brute (i + 1), 2e9);
}

bool smaller (int i, double x) {
    if (x < 1)
        return 0;
    if (i == n)
        return a[i] < x;
    return smaller (i + 1, log (x) / log (a[i]));
}

int turn (int x, int mod) {
    x %= mod;
    return x < 0 ? x + mod : x;
}

int cal (int i, int mod) {
    int f;
    if (mod == 1)
        return 0;
    if (i == n)
        return a[i] % mod;
    if (__gcd (a[i], mod) == 1)
        return power (a[i], cal (i + 1, phi[mod]), mod);
    auto [g, K, N] = len (a[i], mod);
    if (smaller (i + 1, N))
        return power (a[i], brute (i + 1), mod);
    return K * power (a[i], turn (cal (i + 1, phi[mod / g]) - N, phi[mod / g]), mod / g) % mod;
}

void solve() {
    FOR (i, 1, n) cin >> a[i];
    cin >> k;
    cout << cal (1, k) << '\n';
}

int32_t main() {
    ios::sync_with_stdio (false), cin.tie (0);
    sieve();
    while (cin >> n && n)
        solve();
}
