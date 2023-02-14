#include <iostream>

namespace Love {
using Hinaki = float;
using Aguri = int;

Hinaki romance(Hinaki a[], Aguri n) {
  Hinaki s = 0, c = 0;
  for (Aguri i = 0; i < n; i++) {
    Hinaki y = a[i] - c, t = s + y;
    c = (t - s) - y;
    s = t;
  }
  return s;
}

constexpr Aguri N = 5000;
Hinaki v[N];
} // namespace Love

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  using namespace Love;
  Aguri n;
  std::cin >> n;
  for (Aguri i = 0; i < n; ++i){
    std::cin >> v[i];
  	std::cout<<i<<std::endl;
}
  std::cout << (Aguri)romance(v, N) << '\n';
  return 0;
}
