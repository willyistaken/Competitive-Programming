#include <bits/stdc++.h>
using namespace std;
int clean = 0;
bool bigger(const vector<int> a, const vector<int> b) {
  if (a.size() > b.size()) {
    return true;
  }
  if (b.size() > a.size()) {
    return false;
  }
  for (int i = a.size() - 1; i >= 0; i--) {
    if (a[i] > b[i]) {
      return true;
    }
    if (b[i] > a[i]) {
      return false;
    }
  }
  clean = 1;
  return false;
}
int main() {
  string as, bs;
  cin >> as >> bs;
  // as="1000";bs="2";
  vector<int> a;
  vector<int> b;
  for (int i = as.size() - 1; i >= 0; i--) {
    a.push_back(as[i] - '0');
    // a[i]-='0';
  }
  for (int j = bs.size() - 1; j >= 0; j--) {
    b.push_back(bs[j] - '0');
    // b[j]-='0';
  }
  int ans[50] = {0};

  while (bigger(a, b)) {
    vector<int> shiftb = b;
    int shiftd = a.size() - b.size() - 1;
    for (int i = 0; i < shiftd - 1; i++) {
      shiftb.insert(shiftb.begin(), 0);
    }
    int length = shiftb.size();
    while (bigger(a, shiftb)) {
      for (int i = 0; i < length; i++) {
        a[i] -= shiftb[i];
      }
      for (int i = 0; i <= a.size() - 1; i++) {
        if (a[i] < 0) {
          a[i + 1] -= 1;
          a[i] += 10;
        }
      }
      if (a.back() == 0) {
        a.pop_back();
      }
      if (shiftd == 0) {
        ans[0] += 1;
      } else {
        cout << "hello" ans[shiftd - 1] += 1;
      }
    }
  }

  if (clean == 1) {
    ans[0] += 1;
  }
  for (int i = 0; i < 50; i++) {
    if (ans[i] >= 10) {
      ans[i + 1] += (ans[i] - ans[i] % 10) / 10;
      ans[i] = ans[i] % 10;
    }
  }
  int clean2 = 0;
  for (int i = 49; i >= 0; i--) {
    if (ans[i] != 0 || clean2 == 1) {
      clean2 = 1;
      cout << ans[i];
    }
  }
  /*     cout << "    ";
      while (a.back() == 0)
      {
          a.pop_back();
      }
      if (clean == 1)
      {
          cout << 0;
          return 0;
      }
      while (a.size() > 0)
      {
          cout << a.back();
          a.pop_back();
      } */
}