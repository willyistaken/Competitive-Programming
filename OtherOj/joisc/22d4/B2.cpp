#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n); for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto Check = [&](int i, int l, int r) {
        long long s = a[i];
        int L = i, R = i;
        while (L > l || R < r) {
            if (L > l && s >= a[L - 1]) {
                s += a[L - 1];
                L--;
                continue;
            }
            if (R < r && s >= a[R + 1]) {
                s += a[R + 1];
                R++;
                continue;
            }
            break;
        }
        return (L == l && R == r);
    };
    int q;
    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y;
            cin >> x >> y;
            --x;
            a[x] = y;
        } else {
            int l, r;
            cin >> l >> r;
            --l;
            --r;
            int res = 0;
            for (int i = l; i <= r; i++) {
                if (Check(i, l, r)) {
                    res += 1;
                }
            }
            cout << res << '\n';
        }
    }
    return 0;
}
