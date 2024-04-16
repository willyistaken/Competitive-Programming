#include <cstdio>
#include <string>
#include <vector>

// Functions to be implemented in the solution.
std::vector<int> construct(int n, const std::vector<int>& C);

int main() {
    int n_case, len, n;
    scanf("%d", &n_case);
    for (int i = 0; i < n_case; ++i) {
        scanf("%d %d", &len, &n);
        std::vector<int> c(n);
        for (int j = 0; j < n; ++j) scanf("%d", &c[j]);
        std::vector<int> output = construct(len, c);
        printf("%lu", output.size());
        for (size_t j = 0; j < output.size(); ++j) printf(" %d", output[j]);
        printf("\n");
    }
    return 0;
}
