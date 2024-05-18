#include "fun.h"

#include <vector>

std::vector<int> createFunTour(int N, int Q) {
  int H = hoursRequired(0, N - 1);
  int A = attractionsBehind(0, N - 1);
  return std::vector<int>(N);
}
