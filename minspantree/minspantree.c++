#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <unordered_set>

using namespace std;

struct Edge {
    int u;
    int v;
    int w;
    Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
    bool operator<(const Edge& rhs) const
    {
        return w < rhs.w;
    }
};

vector<vector<Edge>> g(20000, vector<Edge>());
vector<bool> visited(20000);
priority_queue<Edge> pq;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> tree;

long long prim(int s) {
    for (auto& e : g[0]) {
        pq.emplace(e);
    }
    long long cost;
    while(!pq.empty()) {
        auto e = pq.top(); pq.pop();
        if(!visited[e.u]) {
            visited[e.u] = true;
            for (auto& edge : g[e.u]) {
                pq.emplace(edge);
            }
        }
        if(!visited[e.v]) {
            visited[e.v] = true;
            for (auto& edge : g[e.v]) {
                pq.emplace(edge);
            }
        }
        cost += e.w;
        tree.emplace(min(e.u, e.v), max(e.u, e.v));
    }
    return cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m;
    while (true) {
        cin >> n >> m;
        if (!n && !m) return 0;
        int u, v, w;
        fill(g.begin(), g.begin() + n, vector<Edge>());
        fill(visited.begin(), visited.begin() + n, false);
        tree = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>();
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            g[u].emplace_back(u, v, w);
            g[v].emplace_back(v, u, w);
        }
        long long cost = prim(0);
        if (tree.size() != n - 1) cout << "Impossible\n";
        else {
            cout << cost << "\n";
            while(!tree.empty()) {
                auto [u,v] = tree.top(); tree.pop();
                cout << u << " " << v << "\n";
            }
        }
    }
}
