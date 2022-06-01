#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    printf("%d %d\n", 100, 150);
    for (int i = 1; i <= 100; i += 2) {
        cout << i % 100 << " " << (i + 2) % 100 << endl;
    }
    for (int i = 2; i <= 100; i += 2) {
        cout << i << " " << (i + 1) % 100 << endl;
        cout << i << " " << (i - 1) % 100 << endl;
    }

    return 0;
}