#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    ll ans = 0;
    sort(arr, arr + n);
    ll sum = arr[0];
    for (int i = 1; i < n; i++) {
        ans += sum;
        sum += arr[i];
    }
    cout << ans + sum << endl;

    return 0;
}