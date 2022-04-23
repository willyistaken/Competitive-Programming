#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[220001];
queue<int> q[220001];
vector<int> ans;
int main() {
    cin >> t;
    while (t--) {
        ans.clear();
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            q[a[i]].push(i);
        }
        int l = 1, r = 0;
        while (l <= n) {
            r = l;
            for (int i = 0; i <= n + 1; i++) {
                if (q[i].empty()) {
                    ans.push_back(i);
                    break;
                }
                r = max(r, q[i].front());
            }
            for (int i = l; i <= r; i++) {
                q[a[i]].pop();
            }
            l = r + 1;
        }
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
}