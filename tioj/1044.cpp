#include <stdio.h>
#include "lib1044.h"
int main(void) {
    int n;
    n = Initialize();
    int low = 0;
    int high = n;
    int ret;
    int mid;
    while (low <= high) {
        mid = low + ((high - low) / 2);
        if (Guess(mid) == mid) {
            low = mid + 1;
        }
        if (Guess(mid) == 1) {
            if (Guess(mid - 1) == mid - 1) {
                ret = mid;
                break;
            } else {
                high = mid - 1;
            }
        }
    }
    Report(mid);
    return 0;
}