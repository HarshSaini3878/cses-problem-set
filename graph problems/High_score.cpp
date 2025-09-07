#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 1e18;

struct Edge {
    int u, v;
    ll w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    vector<vector<int>> g(n + 1), rg(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        ll x;
        cin >> a >> b >> x;
        edges[i] = {a, b, x};
        g[a].push_back(b);
        rg[b].push_back(a);
    }

    // Bellman-Ford for longest path
    vector<ll> dist(n + 1, -INF);
    dist[1] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (auto &e : edges) {
            if (dist[e.u] == -INF) continue;
            if (dist[e.u] + e.w > dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    // Detect positive cycles
    vector<int> cycle_nodes;
    for (auto &e : edges) {
        if (dist[e.u] == -INF) continue;
        if (dist[e.u] + e.w > dist[e.v]) {
            cycle_nodes.push_back(e.v);
        }
    }

    if (!cycle_nodes.empty()) {
        // Reachable from 1
        vector<int> vis1(n + 1, 0), vis2(n + 1, 0);
        queue<int> q;

        // From start (1)
        q.push(1);
        vis1[1] = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : g[u]) if (!vis1[v]) {
                vis1[v] = 1;
                q.push(v);
            }
        }

        // From end (n) on reversed graph
        q.push(n);
        vis2[n] = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : rg[u]) if (!vis2[v]) {
                vis2[v] = 1;
                q.push(v);
            }
        }

        // Check if any cycle node is useful
        for (int v : cycle_nodes) {
            if (vis1[v] && vis2[v]) {
                cout << -1 << "\n";
                return 0;
            }
        }
    }

    cout << dist[n] << "\n";
    return 0;
}
