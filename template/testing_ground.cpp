#include <iostream>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <queue>
#include <vector>
#define lld long long
#define PB push_back
#define F first
#define S second
#define jizz cin.tie(0);ios_base::sync_with_stdio(0);
#define endl '\n'
using namespace std;
typedef pair<int,lld> Pair;
struct Edge{
    int from,to;
    lld w;
    bool operator<(const Edge &x)const{
        return w < x.w;
    }
}E[500005];
struct DJS{
    int p[1005];
    void init(){for(int i = 0 ; i < 1005; i++)p[i] = i;}
    int query(int x){return p[x] == x?x:p[x] = query(p[x]);}
    void unite(int x,int y){
        x = query(x);
        y = query(y);
        p[x] = y;
    }
    bool same(int x,int y){return query(x) == query(y);}
}djs;
lld mst,smst;
vector<Pair> v[1005];
lld p[1005][12],mx[1005][12];
int in[1005],out[1005],t;
bool isfa(int a,int b){return in[a] <= in[b] && out[a] >= out[b];}
void DFS(int now,int fa,lld l){
    in[now] = ++t;
    p[now][0] = fa;
    mx[now][0] = l;
    for(int i = 1 ;i < 12 ; i++){
        p[now][i] = p[p[now][i-1]][i-1];
        mx[now][i] = max(mx[now][i-1],mx[p[now][i-1]][i-1]);
    }
    for(Pair i : v[now]){
        if(i.F != fa)DFS(i.F,now,i.S);
    }
    out[now] = ++t;
}
lld LCA(int a,int b){
    lld maxx = 0;
    if(a == b)return 0;
    if(isfa(b,a))swap(a,b);
    if(!isfa(a,b)){
        for(int i = 11; i >= 0 ; i--){
            if(!isfa(p[a][i],b)){
                maxx = max(maxx,mx[a][i]);
                a = p[a][i];
            }
        }
        maxx = max(maxx,mx[a][0]);
        a = p[a][0];
    }
    for(int i = 11; i >= 0 ; i--){
        if(!isfa(p[b][i],a)){
            maxx = max(maxx,mx[b][i]);
            b = p[b][i];
        }
    }
    return max(maxx,mx[b][0]);
}
int main(){jizz
    out[0] = 2147483647;
    djs.init();
    int n,m;cin >> n >> m ;
    for(int i = 0 ; i < m ; i++)
        cin >> E[i].from >> E[i].to >> E[i].w;
    sort(E,E+m);
    queue<int> q;
    int count = 0;
    for(int i = 0 ; i < m ; i++){
        if(!djs.same(E[i].from,E[i].to)){
            djs.unite(E[i].from,E[i].to);
            v[E[i].from].PB({E[i].to,E[i].w});
            v[E[i].to].PB({E[i].from,E[i].w});
            mst += E[i].w; 
            count++;
        }else q.push(i);
    }
    if(count != n-1)return cout << "-1 -1" << endl ,0;  
    smst = (1LL << 62);
    DFS(1,0,0);
    while(!q.empty()){
        int tmp = q.front();q.pop();
        smst = min(smst,mst-LCA(E[tmp].from,E[tmp].to)+E[tmp].w);
    }
    cout << mst << ' ' << (smst == (1LL << 62) ? -1:smst ) << endl;
    return 0;
}
