#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
struct side {
    int l;
    int r;
    int h;
    char type;
};
struct node {
    int ans = 0;
    int addtag = 0;
    int len;
    int get_ans() { return (addtag) ? len : ans; }
};

void add(int ind, int v, vector<node>& segtree) {
    segtree[ind].addtag += v;
    if (segtree[ind].addtag >= 0) return;
    segtree[ind].addtag = 0;
    if (ind < n) {
        add(2 * ind, v, segtree);
        add(2 * ind + 1, v, segtree);
        segtree[ind].ans =
            segtree[2 * ind].get_ans() + segtree[2 * ind + 1].get_ans();
    }
    return;
}

void push(int ind, vector<node>& segtree) {
    ind >>= 1;
    while (ind) {
        segtree[ind].ans =
            segtree[2 * ind].get_ans() + segtree[2 * ind + 1].get_ans();
        ind >>= 1;
    }
    return;
}

void upd(int l, int r, int v, vector<node>& segtree) {
    l += n;
    r += n;
    while (l < r) {
        if (l % 2) {
            add(l, v, segtree);
            push(l, segtree);
            l++;
        }
        if (r % 2) {
            r--;
            add(r, v, segtree);
            push(r, segtree);
        }
        l >>= 1;
        r >>= 1;
    }
}

void built(int ind, vector<node>& segtree) {
    if (ind >= n) return;
    built(ind * 2, segtree);
    built(2 * ind + 1, segtree);
    segtree[ind].len = segtree[2 * ind].len + segtree[2 * ind + 1].len;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    vector<side> process;
    set<int> tempset;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        tempset.insert(l);
        tempset.insert(r);
        int d, t;
        cin >> d >> t;
        process.push_back({l, r, d, 1});
        process.push_back({l, r, t, -1});
    }

    unordered_map<int, int> cc;
    int acc[tempset.size()];
    for (auto i : tempset) {
        acc[cc.size()] = i;
        cc.insert({i, cc.size()});
    }
    n = cc.size() - 1;
    vector<node> segtree(2 * n);
    for (int i = 0; i < n; i++) {
        segtree[i + n].len = acc[i + 1] - acc[i];
    }

    built(1, segtree);

    sort(process.begin(), process.end(),
         [](const side& a, const side& b) { return a.h < b.h; });

    int starty = 0;
    ll ans = 0;
    for (auto t : process) {
        ll now = segtree[1].get_ans();
        ans += (t.h - starty) * now;
        upd(cc[t.l], cc[t.r], (int)t.type, segtree);
        starty = t.h;
    }
    cout << ans << endl;
    return 0;
}

/*
9
10 12 1 4
4 10 9 15
12 15 5 6
1 17 17 18
3 18 2 13
10 13 0 5
2 8 11 13
3 5 0 12
9 12 12 15
209
*/