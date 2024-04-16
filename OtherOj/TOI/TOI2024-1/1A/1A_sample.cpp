#include <vector>

// Functions provided to the solution.
std::vector<int> activate_sonar_system(int k, const std::vector<int>& p);

std::vector<int> detect_debris(int n, int m, int L, int R) {
  // 這邊填入程式碼，下面這個是範例。不保證任何得分。

  // 在題本中 n=2, m=2, L=1, R=8。
  std::vector<int> r1 = activate_sonar_system(4, {1, 5});
  // 回傳 [1, 0]
  std::vector<int> r2 = activate_sonar_system(2, {1, 3});
  // 回傳 [0, 1]
  return {3, 4};
}
