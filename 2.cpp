#include <bits/stdc++.h>
using namespace std;
bool touch(long long x, long long y, long long ox, long long oy)
{
    if (x == ox || y == oy)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long n, m;
    cin >> n >> m;
    long long q;
    cin >> q;
    long long ans = 0;
    for (int i = 0; i < q; i++)
    {
        long long ox, oy, x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2 >> ox >> oy;
        if ((touch(x1, y1, ox, oy) && touch(x2, y2, ox, oy)) || (x1==x2&&y1==y2) )
        {
            ans++;
        }
    }
    cout << ans << endl;
}