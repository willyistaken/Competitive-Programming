// dearrangement
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long;
long long ans[20] = {1,
                     0,
                     1,
                     2,
                     9,
                     44,
                     265,
                     1854,
                     14833,
                     133496,
                     1334961,
                     14684570,
                     176214841,
                     2290792932,
                     32071101049,
                     481066515734,
                     7697064251745,
                     130850092279664,
                     2355301661033953,
                     44750731559645106};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    while (cin >> n && n) {
        cout << ans[n] << endl;
    }

    return 0;
}