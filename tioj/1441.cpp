#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    pair<int, int> high = make_pair(0, INT_MAX);
    pair<int, int> low = make_pair(0, -11);
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        pair<int, int> temp = low;
        if (h < high.second) {
            low.first = high.first + 1;
            low.second = h;
        }

        if (h > temp.second) {
            high.first = temp.first + 1;
            high.second = h;
        }
    }
    high.first -= !(high.first % 2);
    cout << high.first << endl;
}