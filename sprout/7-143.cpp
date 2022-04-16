#include <bits/stdc++.h>
using namespace std;
int dp[105][105] = {{0}};
int arr[105];
int sumarr[105];
int solve(int l, int r) {
    if (dp[l][r]) {
        return dp[l][r];
    }
    if (r - l == 1) {
        dp[l][r] = arr[l] + arr[r];
        return arr[l] + arr[r];
    }
    if(r==l){
        dp[l][r]=0;
        return dp[l][r];
    }
    int minv = INT_MAX;
    for (int k = l ; k <=r-1; k++) {
        minv = min(solve(l, k) + solve(k + 1, r) + sumarr[r+1]-sumarr[l], minv);
    }
    dp[l][r] = minv;
    return dp[l][r];
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 105; i++) {
            for (int j = 0; j < 105; j++) {
                dp[i][j] = 0;
            }
        }
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sumarr[0]=0;
        for(int i=1;i<n+1;i++){
            sumarr[i]=arr[i-1]+sumarr[i-1];
        }
        cout << solve(0, n - 1) << endl;
    }
}