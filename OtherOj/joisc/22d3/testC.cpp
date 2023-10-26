/*
If the radiance of a thousand suns were to burst into the sky?
...that would be like the splendor of the mighty one.
*/
#include <bits/stdc++.h>
#define pil pair<int, i64>
#define mp(x, y) make_pair(x, y)
#define all(v) (v).begin(), (v).end()
using i128 = __int128;
using i64 = long long;
using u64 = unsigned long long;

const i64 inf = 1e17;

struct SegmentTree {
    const int n;
    std::vector<std::array<i64, 2>> tag;
    std::vector<std::array<std::array<i64, 2>, 2>> dat;
    SegmentTree(int __n) : n(__n) {
        dat.assign((n << 2) + 5, { }), tag.assign((n << 2) + 5, { });
    }
    inline void push_up(int p) {
        dat[p].fill({ -inf, -inf });

        for (int l = 0; l < 2; l++)
            for (int r = 0; r < 2; r++)
                for (int k = 0; k < 2; k++)
                    dat[p][l][r] = std::max(dat[p][l][r], dat[p << 1][l][k] + dat[p << 1 | 1][k][r]);
    }
    inline void push_tag(int p, int opt, i64 delta) {
        dat[p][opt][opt^1] += delta, tag[p][opt] += delta;
    }
    inline void push_down(int p) {
        for (int opt = 0; opt < 2; opt++)
            if (tag[p][opt])
                push_tag(p << 1, opt, tag[p][opt]), push_tag(p << 1 | 1, opt, tag[p][opt]), tag[p][opt] = 0;
    }
    inline void update(int p, int ql, int qr, int l, int r, int opt, i64 delta) {
		if(ql>qr) return;
        if (l >= ql && r <= qr)
            return push_tag(p, opt, delta);

        push_down(p);
        int mid = (l + r) >> 1;

        if (ql <= mid)
            update(p << 1, ql, qr, l, mid, opt, delta);

        if (qr > mid)
            update(p << 1 | 1, ql, qr, mid + 1, r, opt, delta);

        push_up(p);
    }
	/*
    inline void update(int ql, int qr, int opt, i64 delta) {
        if (ql <= qr)
            update(1, ql, qr, 1, n, opt, delta);
    }
	*/
};

inline void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> vec;
    std::vector<std::tuple<int, int, i64>> opt(n);

    for (int i = 0, t, pos, val; i < n; i++) {
        std::cin >> t >> pos >> val, opt[i] = { t - 1, pos, (i64)val };
        vec.push_back(std::get<1>(opt[i]));
    }

    std::sort(all(vec)), vec.resize(std::unique(all(vec)) - vec.begin());

    SegmentTree seg(vec.size());

    auto ind = [&](const int x) {
        return std::lower_bound(all(vec), x) - vec.begin() + 1;
    };

    std::array<i64, 2> sum = { };

    for (int i = 0; i < n; i++) {
		int pos = std::get<1>(opt[i]);
		int o = std::get<0>(opt[i]);
		int val = std::get<2>(opt[i]);
            int r = ind(pos), l = ind(pos - m);
            seg.update(1,r, (int)vec.size(),1,vec.size(), o, val);
            seg.update(1,r, (int)vec.size(),1,vec.size(), o ^ 1, -val);
            seg.update(1,l, r - 1, 1,vec.size(),o ^ 1, -val);
            sum[o] += val;
        i64 res = std::max(std::max(seg.dat[1][1][1], seg.dat[1][0][1]) + sum[1], std::max(seg.dat[1][0][0],
                           seg.dat[1][1][0]) + sum[0]);
        res = sum[0] + sum[1] - res;
        std::cout << res << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);

    int T = 1;

    // std::cin >> T;
    while (T--)
        solve();

    return 0;
}
