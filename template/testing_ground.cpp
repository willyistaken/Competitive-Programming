#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> d;

int m[2001][2001];
int dp[2001];

int calc(int N, int K)
{
    for(int j=1;j<=N;++j)
    {
        int mx = dp[j-1];
        for(int i=j;i<=N;++i)
        {
            int tmp = dp[i];
            dp[i] = mx + m[ d[i-1].second ][j];
            mx = max(mx, tmp);
            if( dp[i] >=K ) return j;
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N,K,W;
    cin>>N>>K;
    for(int i=1;i<=N;++i)
    {
        cin>>W;
        d.emplace_back(W,i);
    }
    for(int i=1;i<=N;++i)
        for(int j=1;j<=N;++j)
            cin>>m[i][j];
    sort(d.begin(), d.end());
    cout<<calc(N, K)<<'\n';
}
