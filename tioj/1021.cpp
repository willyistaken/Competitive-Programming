#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, k;
    long long ans = 0, i;
    while (cin>>n>>k)
    {
        ans = 0;
        if (k != 0)
            for (i = 1; i <= n; i *= 10)
            {
                int x = n / i;
                ans += x / 10 * i;
                if (k < x % 10)
                    ans += i;
                else if (k == x % 10)
                    ans += n % i + 1;
            }
        else
            for (i = 1; i * 10 <= n; i *= 10)
            {
                int x = n / i / 10;
                ans += (x - 1) * i;
                if ((n / i) % 10)
                    ans += i;
                else
                    ans += n % i + 1;
            }
        cout<<ans<<"\n";
    }
}