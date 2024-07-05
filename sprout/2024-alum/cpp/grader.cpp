#include "my_strcmp.h"
#include <cassert>
#include <cstdio>
#include <ctime>
#pragma GCC optimize("O0")

char x[10];
int main() {
    char y[10];
    int res = 48763;

    scanf("%s", x);
    scanf("%s", y);
    fclose(stdin);
    srand(time(0));
    if (rand() % 2) {
        /*res = */my_strcmp(x, y);
        // Oops! forgot to save the result
    }
    else {
        /*res = */my_strcmp(y, x);
        // Oops! forgot to save the result
    }

    printf("%d\n", res);
    fclose(stdout);
    return 0;
}
