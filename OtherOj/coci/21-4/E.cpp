#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


vector<int> side[61];
int dep[61];
int pa[61];

void dfs(int cur,int p) {
    pa[cur]=p;
    dep[cur] = dep[p]+1;
    for(auto i : side[cur]) {
        if(!pa[i]) dfs(i,cur);
    }
}

int dsu[61];
int n;
void init() {
    for(int i=0; i<=n; i++) dsu[i] = i;
}

int query(int a) {
    if(dsu[a]==a) return a;
    dsu[a] = query(dsu[a]);
    return dsu[a];
}

void join(int a,int b) {
    a = query(a);
    b=  query(b);
    dsu[a]=b;
}
map<pair<int,int>,int> mp;

int mk(int a,int b) {
    return mp[make_pair(min(a,b),max(a,b))];
}

const int MOD = 1e9+7;
int m,k;
int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    cin>>m>>k;
    for(int i=1; i<n; i++) {
        int a,b;
        cin>>a>>b;
        side[a].push_back(b);
        side[b].push_back(a);
        mp[make_pair(min(a,b),max(a,b))]=i;
    }
    dfs(1,0);
    int pow[n+1];
    pow[0]=1;
    for(int i=1; i<=n; i++) {
        pow[i] = (1LL*pow[i-1]*k)%MOD;
    }
    vector<int> stuff[m];
    for(int i=0; i<m; i++) {
        int a,b;
        cin>>a>>b;
        if(dep[a]>dep[b]) swap(a,b);
        while(dep[b]>dep[a]) {
            stuff[i].push_back(mk(b,pa[b]));
            b = pa[b];
        }
        while(a!=b) {
            stuff[i].push_back(mk(a,pa[a]));
            stuff[i].push_back(mk(b,pa[b]));
            a = pa[a];
            b = pa[b];
        }
    }
    ll sameans = 0;

    for(int mask=1; mask<(1<<m); mask++) {
        init();
        for(int i=0; i<m; i++) {
            if((mask>>i)&1) {
                for(int j =1; j<stuff[i].size(); j++) {
                    join(stuff[i][j],stuff[i][j-1]);
                }
            }
        }
        int cnt = 0;
        for(int i=1; i<n; i++) {
            query(i);
            if(i==dsu[i]) {
                cnt++;
            }
        }
        if(__builtin_popcount(mask)%2) {
            sameans+=pow[cnt];
        } else {
            sameans-=pow[cnt];
        }
        sameans%=MOD;
        if(sameans<0) sameans+=MOD;

    }
    ll ans = pow[n-1];
    ans-=sameans;
    ans%=MOD;
    if(ans<0) ans+=MOD;
    cout<<ans<<"\n";


    return 0;
}
