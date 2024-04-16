#include <cstdio>
#include <vector>

// Functions to be implemented in the solution.
std::vector<int> count(const std::vector<int> &a);

int main() {
    int n_case, n;
    scanf("%d", &n_case);
    for (int i = 0; i < n_case; ++i) {
        scanf("%d", &n);
        std::vector<int> a(n);
        for (int j = 0; j < n; ++j) scanf("%d", &a[j]);
        std::vector<int> output = count(a);
        for (int j = 0; j < n - 2; ++j) {
            printf("%d%c", output[j], j == n-3? '\n':' ');
        }
    }
    return 0;
}
