#include <cstdio>
#include <cmath>

int s[21] = {
    sqrt(0),
    sqrt(1),
    sqrt(2),
    sqrt(3),
    sqrt(4),
    sqrt(5),
    sqrt(6),
    sqrt(7),
    sqrt(8),
    sqrt(9),
    sqrt(10),
    sqrt(11),
    sqrt(12),
    sqrt(13),
    sqrt(14),
    sqrt(15),
    sqrt(16),
    sqrt(17),
    sqrt(18),
    sqrt(19),
    sqrt(20)
};

signed main() {
    int a, b;
    scanf("%d%d", &a, &b);
    for (int i = a; i <= b; i++)
        puts(i - 0.001 <= s[i] * s[i] && s[i] * s[i] <= i + 0.001 ? "Yes" : "No");
}
