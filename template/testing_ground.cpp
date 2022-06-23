//   __________________
//  | ________________ |
//  ||          ____  ||
//  ||   /\    |      ||
//  ||  /__\   |      ||
//  || /    \  |____  ||
//  ||________________||
//  |__________________|
//  \###################\
//   \###################\
//    \        ____       \
//     \_______\___\_______\
// An AC a day keeps the doctor away.

#pragma g++ optimize("Ofast")
#pragma loop_opt(on)
#include <bits/stdc++.h>
#ifdef local
#define debug(x) (cerr<<#x<<" = "<<(x)<<'\n')
#else
#define debug(x) ((void)0)
#endif // local

using namespace std;
typedef int64_t ll;
constexpr ll N = 100025, INF = 1e18, MOD = 1000000007, K = 256, inf = 1e9;

struct FenwickTree{
    ll sum[N],n;
    void init(ll v[],int _n) {
        n = _n;
        for(int i = 1; i <= n; i++) sum[i] = v[i] - v[i-(i&-i)];
    }
    ll query(int p) {
        ll res = 0;
        for(; p; p-=p&-p) res += sum[p];
        return res;
    }
    void edit(int p,ll d) {
        for(; p<=n; p+=p&-p) sum[p] += d;
    }
} BIT;
struct SegmentTree {
    ll seg[N<<1],n;
    void init(ll v[],int _n) {
        n = _n;
        for(int i = 0; i < n; i++) seg[i+n] = v[i];
        for(int i = n-1; i > 0; i--) seg[i] = __gcd(seg[i<<1],seg[i<<1|1]);
    }
    ll query(int l,int r) {
        ll res = 0;
        for(l+=n,r+=n; l<r; l>>=1,r>>=1) {
            if(l&1) res = __gcd(res,seg[l++]);
            if(r&1) res = __gcd(res,seg[--r]);
        }
        return abs(res);
    }
    void edit(int p,ll d) {
        for(seg[p+=n]+=d; p>1; p>>=1) seg[p>>1] = __gcd(seg[p],seg[p^1]);
    }
} sgt;

int n,q;
ll v[N];
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> v[i];
    BIT.init(v,n);
    for(int i = 0; i < n; i++) v[i] = v[i+1]-v[i];
    sgt.init(v,n);
    while(q--) {
        int tp,l,r;
        ll k;
        cin >> tp;
        if(tp == 1) {
            cin >> l >> r >> k;
            BIT.edit(l,k);
            BIT.edit(r+1,-k);
            sgt.edit(l-1,k);
            sgt.edit(r,-k);
        }else {
            cin >> l >> r;
            cout << abs(__gcd(BIT.query(r), sgt.query(l,r))) << '\n';
        }
    }
}


