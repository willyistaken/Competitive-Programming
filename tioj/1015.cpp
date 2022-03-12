#include <bits/stdc++.h>
using namespace std;

int main() {
  while (true) {
    long long n, m;
    cin >> n >> m;
    if (n == 0 && m == 0)
      return 0;
    long long i = min(n, m);
    cout << ((i + 1) * m * n) - ((i * i + i) * (m + n) / 2) +
                (i * (i + 1) * (2 * i + 1) / 6)
         << endl;
  }
}