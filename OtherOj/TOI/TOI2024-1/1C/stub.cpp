#include <cstdio>
#include <vector>
#include <utility>

// Functions to be implemented in the solution.
void initialize(int n, std::vector<std::pair<int, int>> segments);
bool has_route(int s, int t, long long k);

int main() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    std::vector<std::pair<int, int>> segments(m);
    for (auto &[u, v] : segments)
        scanf("%d %d", &u, &v);
    initialize(n, segments);
    for (int i = 0; i < q; i++) {
        int s, t;
        long long k;
        scanf("%d %d %lld", &s, &t, &k);
        if (has_route(s, t, k))
            puts("true");
        else
            puts("false");
    }
    return 0;
}
