#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <climits>
#include <string>
#include <unordered_map>
using namespace std;

typedef long long LL;
#define INF LONG_LONG_MAX

int n;

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
            vector<bool> visited(N, false);
            res = dfs(S, T, min_flow, INT_MAX, visited);
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
    cin >> n;
    int names = 0;
    unordered_map<string, int> indices;
    unordered_map<int, string> naming;
    string a, b;
    int d;
    vector<LL> given;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> d;
        if (indices.find(a) == indices.end()) {
            indices[a] = names++;
            naming[indices[a]] = a;
        } 
        if (indices.find(b) == indices.end()) {
            indices[b] = names++;
            naming[indices[b]] = b;
        } 
        while(given.size() < names) {
            given.push_back(0);
        }
        given[indices[a]] -= d;
        given[indices[b]] += d;
    }


    int s = names * 2;
    int t = s + 1;
    ScalingFlow flow(t + 1);
    for (int i = 0; i < names; i++) {
        if (! (i < given.size())) {cout << "fuck"; return 0;}
        flow.AddEdge(s, i, given[i]);
        for (int j = 0; j < names; j++) {
            if (j == i) continue;
            flow.AddEdge(i, names + j, INF);
        }
        flow.AddEdge(i + names, t, -given[i]);
    }

    flow.MaxFlow(s, t);
    for (auto edge : flow.edges) {
        if (edge.flow > 0 && edge.u < names && edge.v >= names && edge.v - names < names && edge.v < s && edge.v - names >= 0) {
            if (edge.u >= naming.size() || edge.v - names >= naming.size() || edge.v - names < 0) {
                cout << edge.u << " " << edge.v << " " << s << " " << t << " " << naming.size();
                return 0;
            }
            cout << naming[edge.u] << " " << naming[edge.v - (names)] << " " << edge.flow << "\n";
        }
    }
    cout << "settled\n";

    return 0;
}