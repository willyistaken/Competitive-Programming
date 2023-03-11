#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int factorial[13] = {1,    1,     2,      6,       24,       120,      720,
                     5040, 40320, 362880, 3628800, 39916800, 479001600};
int main() {
    int n;
    ll m;
    while (cin >> n >> m && n && m) {
        m -= 1;
        m %= factorial[n];
        vector<char> arr;
        for (int i = 0; i < n; i++)
            arr.push_back('A' + i);
        for (int i = n - 1; i >= 0; i--) {
            putchar(arr[m / factorial[i]]);
            arr.erase(arr.begin() + (m / factorial[i]));
            m %= factorial[i];
            putchar(((i) ? ' ' : '\n'));
        }
    }

    return 0;
}
