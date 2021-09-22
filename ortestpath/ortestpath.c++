#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <climits>
using namespace std;

int n, m, s, t;

typedef long long LL;
#define INF LONG_LONG_MAX

struct Edge
{
    int u, v;
    LL cap, flow;
    Edge() {}
    Edge(int u, int v, LL cap) : u(u), v(v), cap(cap), flow(0) {}
};

struct ScalingFlow
{
    int N;
    vector<Edge> edges;
    vector<vector<int>> graph;

    ScalingFlow(int N) : N(N), edges(0), graph(N) {}

    void AddEdge(int u, int v, LL cap)
    {
        if (u != v)
        {
            //Creates a edge
            edges.emplace_back(u, v, cap); 
            //Reference to just added edge
            graph[u].emplace_back(edges.size() - 1); 

            //Back edge
            edges.emplace_back(v, u, 0);
            graph[v].emplace_back(edges.size() - 1);
        }
    }

    LL dfs(int u, int sink, LL threshold, LL bottleneck, vector<bool> &visited)
    {
        if (u == sink)
        {
            return bottleneck;
        }
        visited[u] = true;
        for (int& er : graph[u])
        {
            Edge& edge = edges[er];
            LL amount = edge.cap - edge.flow;
            if (!visited[edge.v] && amount >= threshold)
            {
                if(bottleneck > amount) bottleneck = amount;
                if(LL res = dfs(edge.v, sink, threshold, bottleneck, visited)) 
                {
                    edge.flow += res;
                    edges[er^1].flow -= res; // ^1 gives the corresponding edge
                    return res;
                }
            }
        }
        return 0;
    }

    LL MaxFlow(int S, int T)
    {
        LL min_flow = INF;
        LL res;
        LL sum = 0;
        while (min_flow)
        {
            vector<bool> visited(n, false);
            res = dfs(s, t, min_flow, INT_MAX, visited);
            if (!res)
                min_flow >>= 1;
            else
                sum += res;
        }
        return res;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> s >> t;
    int u, v, b;
    ScalingFlow flow(n * 2);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> b;
        if (!b) {
            flow.AddEdge(u, n + u, 1);
            flow.AddEdge(n + u, v, INF);
            flow.AddEdge(v, n + v, 1);
            flow.AddEdge(n + v, u, INF);
        }
        else {

        }
    }

    flow.MaxFlow(s, t);
    
    vector<bool> visited(n, false);
    flow.dfs(s, t, 1, 1, visited);
    cout << count(visited.begin(), visited.end(), true) << '\n';
    for (int i = n - 1; i >= 0; i--)
    {
        if (visited[i])
            cout << i << '\n';
    }
}