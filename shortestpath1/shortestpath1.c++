#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <unordered_set>

using namespace std;

struct Edge {
    int v;
    int w;
    Edge(int _v, int _w) : v(_v), w(_w) {}
};

vector<vector<Edge>> g(10000, vector<Edge>());
vector<int> d(10000);
vector<bool> visited(10000);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

void shortestpath(int s) {
    pq.emplace(0, s);
    while(!pq.empty()) {
        auto [di, u] = pq.top(); pq.pop();
        if(visited[u]) continue;
        visited[u] = true;
        d[u] = di;
        for (auto& e : g[u]) {
            pq.emplace(di + e.w, e.v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m, q, s;
    while (true) {
        cin >> n >> m >> q >> s;
        if (!n && !m && !q && !s) return 0;
        int u, v, w;
        fill(g.begin(), g.begin() + n, vector<Edge>());
        fill(d.begin(), d.begin() + n, -1);
        fill(visited.begin(), visited.begin() + n, false);
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            g[u].emplace_back(v, w);
        }
        shortestpath(s);
        int query;
        for (int i = 0; i < q; i++) {
            cin >> query;
            if(d[query] == -1) cout << "Impossible\n";
            else cout << d[query] << "\n";
        }
        cout << "\n";
    }
}
