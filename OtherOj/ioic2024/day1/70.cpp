#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int N, L, K, T;
    string s = "Impossible";
    cin >> N >> L >> K >> T;

    vector<pair<int, int>> arr(N);
    for (auto &[l, t] : arr)
        cin >> l >> t;

    sort(arr.begin(), arr.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    });

    auto quited = [&](string &verdict) {
        int ans = 0, lv = 1;

        priority_queue<int, vector<int>, greater<int>> min_heap;

        for (int pt = 0, exp = 0; lv < L;) {
            while (pt < N && arr[pt].first <= lv)
                min_heap.push(arr[pt++].second);
            if (min_heap.empty()) return verdict;

            ans += min_heap.top();
            min_heap.pop();

            exp += 1;
            if (exp == K) exp = 0, lv += 1;
        }

        if (ans > T)
            verdict = "Time Limit Exceeded";
        else {
            cout << ans << "\n";
            exit(0);
        }

        return verdict;
    }(s);

    cout << quoted(s) << "\n";
}
