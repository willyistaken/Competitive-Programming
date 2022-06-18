#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define AI(x) begin(x),end(x)
#define ll long long int
#define endl '\n'
#ifdef DEBUG
#define debug(args...) LKJ("[ "+string(#args)+" ]", args)
template<class I> void LKJ(I&&x){ cerr << x << '\n'; }
template<class I, class...T> void LKJ(I&&x, T&&...t){ cerr << x << ", ", LKJ(t...); }
template<class I> void OI(I a, I b){ while(a < b) cerr << *a << " \n"[next(a) == b], ++a; }
#else
#define debug(...) 0
#define OI(...) 0
#endif
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int maxn = 500005;
vector<int>adj[maxn];
vector<int>fa(maxn,0);
vector<int>arr(maxn,0);
int n, k;
int ans = 0;
pair<int, queue<int>> dfs(int x){
    int md = arr[fa[x]];
    queue<int> ret;
    ret.push(arr[x]);
    for (auto i : adj[x]) {
        debug(x,i);
        pair<int,queue<int> > temp;
        int v = temp.first;
        queue<int> que = temp.second;
        if (que.size()>=k) {
            v = v ^ que.front();
            que.pop();
        }
        v ^= arr[x];
        ans = max(ans, v);
        
        que.push(arr[x]);
        if (que.size()>=k) {
            v = v ^ que.front();
            que.pop();
        }
        if ((v^arr[fa[x]]) >= md) {
            md = v;
            ret = que;
        }
    }
    return {md,ret};
};

signed main() {_
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    for (int i = 1; i < n; ++i) {
        int temp;
        cin >> temp;
//        adj[temp].push_back(i+1);
        fa[i+1] = temp;
    }
    for (int i = 1; i <= n; ++i) {
        int x = i;
        int cur = arr[i];
        ans = max(cur, ans);
        for (int j = 1; j < k; j++) {
            x = fa[x];
            cur = cur ^ arr[x];
            ans = max(cur, ans);
        }
    }
    //dfs(1);
    cout << ans << endl;
    return 0;
}