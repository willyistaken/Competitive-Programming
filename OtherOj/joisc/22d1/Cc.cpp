/**
 ____ ____ ____ ____ ____ ____
||l |||e |||i |||n |||a |||d ||
||__|||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|/__\|
 
**/
 
#include<bits/stdc++.h>
#define endl '\n'
 
using namespace std;
typedef long long ll;
 
void speed()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
const ll mod = 1000000007;
const int maxm = 5e5 + 10;
const int maxn = 5e5 + 10;
 
int n, m;
ll dp[maxn][30];
ll fen[30][maxn];
 
void update(int idx, int pos, ll val)
{
    for (int i = pos; i < maxn; i += (i & -i))
    {
        fen[idx][i] += val;
        if (fen[idx][i] >= mod)
            fen[idx][i] -= mod;
    }
}
 
ll sum(int idx, int pos)
{
    ll s = 0;
    for (int i = pos; i > 0; i -= (i & -i))
    {
        s += fen[idx][i];
        if (s >= mod)
            s -= mod;
    }
    return s;
}
ll query(int idx, int l, int r)
{
    ll val = sum(idx, r) - sum(idx, l - 1);
    if (val < 0)
        val += mod;
    return val;
}
 
 
pair < int, int > con[maxm];
 
int fac[2][maxn];
ll temp[30];
 
vector < int > add[2][maxn], rem[2][maxn];
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i ++)
    {
        cin >> con[i].first >> con[i].second;
        if (con[i].first < con[i].second)
        {
            add[0][con[i].first].push_back(con[i].first);
            rem[0][con[i].second].push_back(con[i].first);
        }
        else if (con[i].first > con[i].second)
        {
            add[1][con[i].second].push_back(con[i].second);
            rem[1][con[i].first].push_back(con[i].second);
        }
    }
 
    int sm = 0, bg = 0;
    multiset < int > act0, act1;
    for (int i = 1; i < n; i ++)
    {
        for (int v : add[0][i])
            act0.insert(v);
        for (int v : rem[0][i])
            act0.erase(act0.find(v));
 
        for (int v : add[1][i])
            act1.insert(v);
        for (int v : rem[1][i])
            act1.erase(act1.find(v));
 
 
        if (!act0.empty())
            fac[0][i] = *act0.rbegin();
        if (!act1.empty())
            fac[1][i] = *act1.rbegin();
    }
 
 
 
 
    for (int j = 0; j < 26; j ++)
    {
        dp[1][j] = 1;
    }
 
    for (int i = 1; i <= n - 1; i ++)
    {
 
        for (int j = 0; j < 26; j ++)
        {
            update(j, i, dp[i][j]);
        }
 
        int pt_big = n, pt_small = n;
        pt_big = i - fac[1][i] + 1;
        pt_small = i - fac[0][i] + 1;
        ///cout << i << " " << pt_big << " " << pt_small << endl;
        /**for (int d = 1; d <= m; d ++)
        {
            if (con[d].first == con[d].second)
                continue;
            if (con[d].first < con[d].second)
            {
                if (con[d].first >= i + 1 || con[d].second < i + 1)
                    continue;
 
                pt_small = min(pt_small, i - con[d].first + 1);
            }
            else
            {
                if (con[d].second >= i + 1 || con[d].first < i + 1)
                    continue;
 
                pt_big = min(pt_big, i - con[d].second + 1);
            }
        }*/
        ///cout << i << " : " << pt_big << " : " << pt_small << endl;
 
        for (int c = 0; c < 26; c ++)
        {
            temp[c] = query(c, i - pt_small + 2, i);
        }
 
        ll sum = 0;
        for (int c = 0; c < 26; c ++)
        {
            dp[i + 1][c] += sum;
            if (dp[i + 1][c] >= mod)
                dp[i + 1][c] -= mod;
            sum += temp[c];
            if (sum >= mod)
                sum -= mod;
        }
 
        for (int c = 0; c < 26; c ++)
        {
            temp[c] = query(c, i - pt_big + 2, i);
        }
 
        sum = 0;
        for (int c = 25; c >= 0; c --)
        {
            dp[i + 1][c] += sum;
            if (dp[i + 1][c] >= mod)
                dp[i + 1][c] -= mod;
            sum += temp[c];
            if (sum >= mod)
                sum -= mod;
        }
        /**for (int j = 1; j <= i; j ++)
        {
            if (j < pt_small)
            {
                ll sum = 0;
                for (int c = 0; c < 26; c ++)
                {
                    dp[i + 1][c] += sum;
                    if (dp[i + 1][c] >= mod)
                        dp[i + 1][c] -= mod;
                    sum += dp[i - j + 1][c];
                    if (sum >= mod)
                        sum -= mod;
                }
            }
            if (j < pt_big)
            {
                ll sum = 0;
                for (int c = 25; c >= 0; c --)
                {
                    dp[i + 1][c] += sum;
                    if (dp[i + 1][c] >= mod)
                        dp[i + 1][c] -= mod;
                    sum += dp[i - j + 1][c];
                    if (sum >= mod)
                        sum -= mod;
                }
            }
 
        }*/
 
 
        ///cout << small << " : " << big << endl;
 
    }
 
 
 
    ll ans = 0;
    for (int i = 1; i <= n; i ++)
        for (int c = 0; c < 26; c ++)
        {
            ans = ans + dp[i][c];
            if (ans >= mod)
                ans -= mod;
        }
 
    cout << ans << endl;
 
}
 
int main()
{
    solve();
    return 0;
}
 
