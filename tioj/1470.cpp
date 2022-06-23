#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    int tran[2 * n - 1][2 * m - 1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < 2 * n - 1; i++) {
        for (int j = 0; j < 2 * m - 1; j++) {
            if (i % 2 == j % 2) {
                tran[i][j] = 1;
            } else {
                if (i % 2) {
                    tran[i][j] = arr[i / 2][j / 2] < arr[i / 2 + 1][j / 2];
                } else {
                    tran[i][j] = arr[i / 2][j / 2] < arr[i / 2][j / 2 + 1];
                }
            }
        }
    }
    n = 2 * n - 1;
    m = 2 * m - 1;
    int conti[m] = {0};
    int maxn = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tran[i][j])
                conti[j] += 1;
            else
                conti[j] = 0;
        }
        if (i % 2) continue;
        for (int j = 0; j < m; j += 2) {
            int minn = conti[j];
            for (int k = j; k < m; k++) {
                minn = min(minn, conti[k]);
                if (k % 2 == 0)
                    maxn = max(maxn, ((minn + 1) / 2) * ((k - j + 2) / 2));
            }
        }
    }
    cout << maxn << endl;

    return 0;
}