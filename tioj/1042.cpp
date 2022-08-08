#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e9
#define LINF 1e18
struct MCMF {
    struct Edge {
        int to, cap, rev;
        ll cost;
        Edge() {}
        Edge(int _to, int _cap, int _rev, ll _cost) :
            to(_to), cap(_cap), rev(_rev), cost(_cost) {}
    };
    static const int N = 2000;
    vector<Edge> G[N];
    int n, s, t;
    void init(int _n, int _s, int _t) {
        n = _n, s = _s, t = _t;
        for(int i = 0; i <= n; ++i)
            G[i].clear();
    }
    void add_edge(int from, int to, int cap, ll cost) {
        G[from].emplace_back(to, cap, (int)G[to].size(), cost);
        G[to].emplace_back(from, 0, (int)G[from].size() - 1, -cost);
    }

    bool vis[N];
    int iter[N];
    ll dis[N];
    bool SPFA() {
        for(int i = 0; i <= n; ++i)
            vis[i] = 0, dis[i] = LINF;
        
        dis[s] = 0; vis[s] = 1;
        queue<int> que; que.push(s);
        while(!que.empty()) {
            int u = que.front(); que.pop();
            vis[u] = 0;
            for(auto& e : G[u]) if(e.cap > 0 && dis[e.to] > dis[u] + e.cost) {
                dis[e.to] = dis[u] + e.cost;
                if(!vis[e.to]) {
                    que.push(e.to);
                    vis[e.to] = 1;
                }
            }
        }
        return dis[t] != LINF;
    }

    int dfs(int u, int cur) {
        if(u == t) return cur;
        int ret = 0; vis[u] = 1;
        for(int &i = iter[u]; i < (int)G[u].size(); ++i) {
            auto &e = G[u][i];
            if(e.cap > 0 && dis[e.to] == dis[u] + e.cost && !vis[e.to]) {
                int tmp = dfs(e.to, min(cur, e.cap));
                e.cap -= tmp;
                G[e.to][e.rev].cap += tmp;
                cur -= tmp;
                ret += tmp;
                if(cur == 0) {
                    vis[u] = 0;
                    return ret;
                }
            }
        }
        vis[u] = 0;
        return ret;
    }
    pair<int, ll> flow() {
        int flow = 0; ll cost = 0;
        while(SPFA()) {
            memset(iter, 0, sizeof(iter));
            int tmp = dfs(s, INF);
            flow += tmp, cost += tmp * dis[t];
        }
        return {flow, cost};
    }
};


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	while(cin>>n && n){
		//1 - n boy    n+1 -> 2n girl 2n+1sink 0 source
		MCMF flow;
		flow.init(2*n+2,0,2*n+1);
		for(int i=1;i<=n;i++){
			for(int j=n+1;j<=2*n;j++){
				int k;cin>>k;
				flow.add_edge(i,j,1,-k);
			}
		}
		for(int i=1;i<=n;i++){
			flow.add_edge(0,i,1,0);
			flow.add_edge(i,2*n+1,1,0);
			flow.add_edge(i+n,2*n+1,1,0);
		}
		pair<int,ll> ans = flow.flow();
		
		cout<<-ans.second<<"\n";
	}

	return 0;
}
