#include <bits/stdc++.h>
using namespace std;
//左到右掃一次紀錄每一點右邊的最大值 prefix
// swipe from right to left and record the min of every suffix
// swipe from left to right again and check if it is node;l

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int maxl[n];
        int minr[n];
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        maxl[0] = INT_MAX;
        int maxn = arr[0];
        for (int i = 1; i < n; i++) {
            maxl[i] = maxn;
            maxn = max(maxn, arr[i]);
        }
        minr[n - 1] = INT_MIN;
        int minn = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            minr[i] = minn;
            minn = min(minn, arr[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (maxl[i] < arr[i] && minr[i] > arr[i]) {
                ans++;
            }
        }
        cout << ans << endl;
    }
}