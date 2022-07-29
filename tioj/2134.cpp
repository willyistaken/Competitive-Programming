#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e9
struct Dinic {
    static const int N = 1100;
    struct Edge {
        int to, cap, rev;
        Edge() {}
        Edge(int _to, int _cap, int _rev) :
            to(_to), cap(_cap), rev(_rev) {}
    };

    vector<Edge> G[N];
    int dis[N], iter[N], s, t;

    void init(int n) {
        for(int i = 0; i <= n; ++i)
            G[i].clear();
    }

    void add_edge(int from, int to, int cap) {
        // remind undirected graph
        G[from].emplace_back(to, cap, G[to].size());
        G[to].emplace_back(from, 0, G[from].size() - 1);
    }
   
    void bfs() {
        memset(dis, -1, sizeof(dis));
        dis[s] = 0;
        queue<int> que;
        que.push(s);
        while(!que.empty()) {
            int u = que.front(); que.pop();
            for(auto& edge : G[u]) {
                if(edge.cap > 0 && dis[edge.to] == -1) {
                    dis[edge.to] = dis[u] + 1;
                    que.push(edge.to);
                }
            }
        }
    }

    int dfs(int u, int cur) {
        if(u == t) return cur;
        for(int& i = iter[u]; i < (int)G[u].size(); ++i) {    
            auto& edge = G[u][i];
            if(edge.cap > 0 && dis[u] + 1 == dis[edge.to]) {
                int ans = dfs(edge.to, min(cur, edge.cap));
                if(ans > 0) {
                    // remind undirected graph
                    G[edge.to][edge.rev].cap += ans;
                    edge.cap -= ans;
                    return ans;
                }              
            }
        }
        return 0;
    }

    int flow(int src, int sink) {
        s = src, t = sink;
        int ans = 0;
        while(true) {
            bfs();
            if(dis[sink] == -1) break;
            memset(iter, 0, sizeof(iter));
            int tmp;
            while((tmp = dfs(src, INF)) > 0)
                ans += tmp;
        }
        return ans;
    }
};

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	Dinic flow;
	int n,m,k;cin>>n>>m>>k;
	flow.init(n+m+5);
	for(int i=1;i<=n;i++){
		int ts;cin>>ts;
		while(ts--){
			int g;cin>>g;
			flow.add_edge(i,n+g,1);
		}
	}
	for(int i=1;i<=n;i++){
		flow.add_edge(0,i,1);
		flow.add_edge(n+m+1,i,1);
	}
	flow.add_edge(0,n+m+1,k);
	for(int i=1;i<=m;i++){
		flow.add_edge(i+n,n+m+2,1);
	}
	cout<<flow.flow(0,n+m+2)<<"\n";	
	return 0;
}

// flow template
