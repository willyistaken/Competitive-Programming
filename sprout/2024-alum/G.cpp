#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> t3;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int H, W;
    cin >> H >> W;

    vector<string> graph(H);
    for (auto& s: graph) cin >> s;
    
    pair<int, int> s;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (graph[i][j] == 'o') s = {i, j};
        }
    }


    vector< vector<int> > dist(H, vector<int>(W, 1e8));
    
    priority_queue<t3, vector<t3>, greater<t3>> pq;
    auto& [x0, y0] = s;
    dist[x0][y0] = 0;
    pq.push(t3(0, x0, y0));

    auto push = [&](int x, int y, int d) {
        if (graph[x][y] == '*') return 0;
		if (dist[x][y]>d) {
        	pq.push(t3(d, x, y));
        	dist[x][y] = d;
		}
        return 1;
    };

    while (pq.size()) {
        auto [d, x, y] = pq.top();
        pq.pop();
		if(dist[x][y]!=d) continue;
        // up
        if (graph[x + 1][y] == '*') {
            for (int i = 1; push(x - i, y, d + i); i++);
        }
        // push(x - 1, y, d + 1);

        // down
        push(x + 1, y, d);


        // left and right
        if (graph[x][y + 1] != '*' && !push(x + 1, y + 1, d + 1)) push(x, y + 1, d + 1);
        if (graph[x][y - 1] != '*' && !push(x + 1, y - 1, d + 1)) push(x, y - 1, d + 1);
    }
/*
    for (auto& v: dist) {
        for (auto& n: v) {
            cerr << setw(2) << (n < 100 ? n : -1) << ' ';
        }

        cerr << '\n';
    } 
*/
    /*
    *****
    *-o-*
    **--*
    *****
    */

    int ans = 0;
    for (auto& v: dist) for (auto& n: v) if (n < 1e7) ans = max(ans, n);
    std::cout << ans << '\n';
}
