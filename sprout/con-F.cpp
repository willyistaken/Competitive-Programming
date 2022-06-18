#include <bits/stdc++.h>
using namespace std;
short v,r,m,temp,temp2,temp3, tttt, fa[1030][2];
vector<int>ans;

char dfs(long n) {
    if (m==0) {
        ans.push_back(n);
        tttt = fa[n][0]!=0 ? dfs(fa[n][0]) : -1;
        tttt = fa[n][1]!=0 ? dfs(fa[n][1]) : -1;
    }else{
        switch (m) {
            case 1:
                tttt = fa[n][0]!=0 ? dfs(fa[n][0]) : -1;
                ans.push_back(n);
                tttt = fa[n][1]!=0 ? dfs(fa[n][1]) : -1;
                break;
            default:
                tttt = fa[n][0]!=0 ? dfs(fa[n][0]) : -1;
                tttt = fa[n][1]!=0 ? dfs(fa[n][1]) : -1;
                ans.push_back(n);
        }
    }
    return 'k';
}

signed main() {
    cin >> v >> r >> m;
    v-=2;
    while (v--) {
        cin >> temp >> temp2;
        fa[temp][0] = temp2;
        sort(fa[temp], fa[temp]+2);
    }
    dfs(r);
    for (auto &i : ans) {
        cout << i << " \n"[&i == &ans.back()];
    }
}