#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    set<int> aset;
    for (int i = 0; i < n; i++) {
        string c;
        cin >> c;
        int num;
        cin >> num;
        if (c[0] == 'i') {
            aset.insert(num);
        }
        if (c[0] == 'd') {
            aset.erase(num);
        }
        if (c[0] == 'q') {
            auto high = aset.lower_bound( num);
            auto low = prev(high, 1);
            if (abs(*low - num) < abs(*high - num)) {
                cout << *low;
            }
            if (abs(*low - num) > abs(*high - num)) {
                cout << *high;
            }
            if (abs(*low - num) == abs(*high - num)) {
                cout << *low;
                if (*low != *high) {
                    cout << " " << *high;
                }
            }
            cout << endl;
        }
    }
//this is vim    
}