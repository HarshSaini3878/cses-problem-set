#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 1e18;
const int MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n+1);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }

    vector<ll> dist(n+1, INF);
    vector<ll> ways(n+1, 0);
    vector<int> minEdges(n+1, INT_MAX);
    vector<int> maxEdges(n+1, INT_MIN);

    dist[1] = 0;
    ways[1] = 1;
    minEdges[1] = 0;
    maxEdges[1] = 0;

    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
    pq.push({0,1});

    while (!pq.empty()) {
        auto [d,u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v,w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                ways[v] = ways[u];
                minEdges[v] = minEdges[u] + 1;
                maxEdges[v] = maxEdges[u] + 1;
                pq.push({dist[v], v});
            }
            else if (dist[u] + w == dist[v]) {
                ways[v] = (ways[v] + ways[u]) % MOD;
                minEdges[v] = min(minEdges[v], minEdges[u] + 1);
                maxEdges[v] = max(maxEdges[v], maxEdges[u] + 1);
            }
        }
    }

    cout << dist[n] << " " << ways[n] << " " << minEdges[n] << " " << maxEdges[n] << "\n";
    return 0;
}
