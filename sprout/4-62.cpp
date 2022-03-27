#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > arr(9, vector<int>(9, 0));
int all = 0;
void printsudo() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << arr[i][j];
        }
    }
    cout << endl;
}
bool valid() {
    for (int i = 0; i < 9; i++) {
        int possible[10] = {0};
        for (int j = 0; j < 9; j++) {
            if (arr[i][j] == 0) continue;
            if (possible[arr[i][j]] == 0)
                possible[arr[i][j]] = 1;
            else
                return 0;
        }
    }
    for (int i = 0; i < 9; i++) {
        int possible[10] = {0};
        for (int j = 0; j < 9; j++) {
            if (arr[j][i] == 0) continue;
            if (possible[arr[j][i]] == 0)
                possible[arr[j][i]] = 1;
            else
                return 0;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int possible[10] = {0};
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    if (arr[i * 3 + k][j * 3 + l] == 0) continue;
                    if (possible[arr[i * 3 + k][j * 3 + l]] == 0)
                        possible[arr[i * 3 + k][j * 3 + l]] = 1;
                    else
                        return 0;
                }
            }
        }
    }
    return 1;
}
void solve(int n) {
    if (!all) {
        if (n > 80) {
            ++all;
            printsudo();
        } else {
            int x = n / 9;
            int y = n % 9;
            if (arr[x][y] == 0) {
                for (int i = 1; i < 10; i++) {
                    arr[x][y] = i;
                    if (valid()) {
                        solve(n + 1);
                    }
                }
                arr[x][y] = 0;
            } else {
                solve(n + 1);
            }
        }
    }
}
int main() {
    int t;cin>>t;
    while(t--){
     all = 0;
    string s;cin>>s;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if(s[i*9+j]=='.'){
                arr[i][j]=0;
            }else{
                arr[i][j] = s[i*9+j]-'0';
            }
        }
    }
    solve(0);
    if(!all){
        cout << "No solution.\n";
    }
       
    }
    
}
