#include <iostream>
using namespace std;
int main() {
  unsigned int a, b, ans;
  ans = 0;
  cin >> a;
  cin >> b;
  while (a != b) {
    if (a > b) {
      a >>= 1;
    } else {
      b >>= 1;
    }
    ans += 1;
  }
  cout << ans;
}