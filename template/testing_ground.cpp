#include <cstdio>

const int kMaxN = 1001, kInf = 100000001;
int x[kMaxN][kMaxN];

int main() {
  int N, M;
  scanf("%d%d", &N, &M);
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= N; j++) x[i][j] = kInf;
  }
  for (int i = 0; i <= N; i++) x[i][i] = x[0][i] = 0;
  while (M--) {
    int a, b, d;
    scanf("%d%d%d", &a, &b, &d);
    if (-d < x[b][a]) x[b][a] = -d;
  }
  for (int k = 0; k <= N; k++) {
    for (int i = 0; i <= N; i++) {
      for (int j = 0; j <= N; j++) {
        if (x[i][j] - x[i][k] > x[k][j]) x[i][j] = x[i][k] + x[k][j];
      }
    }
  }
  for (int i = 0; i <= N; i++) {
    if (x[i][i] < 0) {
      puts("-1");
      return 0;
    }
  }
  for (int i = 1; i <= N; i++) printf("%d\n", x[0][i]);
  }
