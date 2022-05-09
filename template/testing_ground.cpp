#include <stdio.h>
int c, dp[1000005], ary[1000005], ptr[1000005], last[1000005];
void backtracking(int now) {
    if (now == 0) {
        return;
    }
    backtracking(last[now]);
    if (c == 0) {
        printf("%d", ary[ptr[now]]);
        c++;
    } else {
        printf(" %d", ary[ptr[now]]);
    }
}
int main() {
    int count, n, i, j, t, temp, maxlen, ans;
    scanf("%d", &count);
    while (count--) {
        scanf("%d", &n);
        for (i = 1; i <= n; i++) {
            scanf("%d", &ary[i]);
        }
        maxlen = 0;
        dp[0] = 0;
        ptr[0] = 0;
        ary[0] = 1000000;
        for (i = 1, maxlen = 0, ans = 0; i <= n; i++) {
            scanf("%d", &temp);
            for (j = 1; j <= n && ary[j] != temp; j++)
                ;
            if ((t = j) <= n) {
                ptr[i] = t;
                for (j = i - 1, dp[i] = 0; j >= 0; j--) {
                    if (ptr[j] != -1 && temp < ary[ptr[j]] && ptr[j] < t &&
                        dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        last[i] = j;
                    }
                }
                if (dp[i] > maxlen) {
                    maxlen = dp[i];
                    ans = i;
                }
            } else {
                ptr[i] = -1;
            }
        }
        c = 0;
        backtracking(ans);
        printf("\n");
    }
    return 0;
}
