
#include <cstdio>
#include <cstdlib>

void dfs(int a, int b) {
  if (a % b == 0) {
    printf("%d", a / b);
    return;
  }
  printf("%d+1/", a / b);
  if (b % (a % b) != 0)
    printf("{");
  dfs(b, a % b);
  if (b % (a % b) != 0)
    printf("}");
  return;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d/%d = ", a, b);
    dfs(a, b);
    puts("");
  }
  return 0;
}