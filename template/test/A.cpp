#include <bits/stdc++.h>
using namespace std;
const int Z = 1.2e5, B = 17;
int N, K, p[Z][B], up[Z][2], d[Z], pE[Z], res[Z];
vector<int> h[Z];
vector<array<int, 2>> g[Z], q0[Z], q1[Z];
vector<array<int, 3>> qQ;
vector<array<int, 4>> pQ;
 
void init(int u) {
	for(int i = 0; i + 1 < B; ++i) p[u][i+1] = p[p[u][i]][i];
	for(auto [v, i] : g[u]) if(v != p[u][0]) {
		p[v][0] = u;
		d[v] = d[u] + 1;
		pE[v] = i;
		if(pE[u] < i) {
			up[v][0] = up[u][0];
			up[v][1] = u;
		} else {
			up[v][0] = u;
			up[v][1] = up[u][1];
		}
		init(v);
	}
}
 
int _u, _v;
 
int lca(int u, int v) {
	bool swapped = 0;
	if((swapped = (d[u] < d[v]))) swap(u, v);
	if(d[u] > d[v]) {
		for(int i = B; i--; ) if((d[u] - d[v] - 1) & (1<<i)) u = p[u][i];
		if(p[u][0] == v) {
			_u = u;
			return v;
		}
		u = p[u][0];
	}
	for(int i = B; i--; ) if(p[u][i] != p[v][i]) u = p[u][i], v = p[v][i];
	if(swapped) swap(u, v);
	_u = u, _v = v;
	return p[u][0];
}
int F[2*Z];
void add(int i, int v) {
	for(++i; i < N + K; i += i&-i) F[i] += v;
}
 
int get(int i) {
	int v {};
	for(++i; i; i -= i&-i) v += F[i];
	return v;
}
 
void dfs(int u) {
	add(pE[u], 1);
	for(auto [j, i] : q1[u]) res[j] -= get(i);
	for(auto [v, i] : g[u]) if(v != p[u][0]) dfs(v);
	for(auto [j, i] : q0[u]) res[j] += get(i);
	for(int v : h[u]) add(pE[v], -1);
}
 
int main() {
	cin >> N >> K;
	// cin
	for(int i {}, j {}; i < N - 1 + K; ++i) {
		char t; int u, v;
		cin >> t >> u; --u;
		if(t == 'S') {
			cin >> v; --v;
			g[u].push_back({v, i});
			g[v].push_back({u, i});
		}
		if(t == 'Q') {
			cin >> v; --v;
			pQ.push_back({j++, i, u, v});
		}
        if(t == 'C') qQ.push_back({j++, i, u});
	}

	// sort by reverse time?
	for(int u = N; u--; ) reverse(begin(g[u]), end(g[u]));

	init(0);
	for(auto [j, i, u] : qQ) {
		q0[u].push_back({j, i});
		q1[up[u][1]].push_back({j, i});
	}
	for(int u = N; u--;) h[up[u][0]].push_back(u);
	dfs(0);
	for(auto [j, i, u, v] : pQ) {
		int w = lca(u, v), val = w == u ? pE[_u] : pE[u];
		if(w != u && w != v && pE[_u] < pE[_v]) val = i; 
		if(u == v || (max(d[up[u][0]], d[up[v][1]]) <= d[w] && val < i)) res[j] = -1;
		else res[j] = -2;
	}
	for(int j = 0; j < K; ++j) {
		if(res[j] < 0) cout << (res[j] & 1 ? "yes\n" : "no\n");
		else cout << 1 + res[j] << '\n';
	}
}
