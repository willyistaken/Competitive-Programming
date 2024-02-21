#include "testlib.h"
#include <vector>
#include <utility>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    vector<pair<int, int>> edges;
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            edges.emplace_back(i, j);
    shuffle(edges.begin(), edges.end());
    edges.resize(m);
    printf("%d %d\n", n, m);
    for (auto [a, b] : edges)
        if (rnd.next(0, 1))
            printf("%d %d\n", a, b);
        else
            printf("%d %d\n", b, a);
}
