#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    vector<int> indeg(n+1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
    }

    // Topological sort (Kahn's algorithm)
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) q.push(i);
    }

    vector<int> topo;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (int v : adj[u]) {
            if (--indeg[v] == 0) q.push(v);
        }
    }

    // DP for longest path
    vector<int> dp(n+1, -1e9), parent(n+1, -1);
    dp[1] = 1; // path starts at 1

    for (int u : topo) {
        if (dp[u] < 0) continue; // unreachable
        for (int v : adj[u]) {
            if (dp[v] < dp[u] + 1) {
                dp[v] = dp[u] + 1;
                parent[v] = u;
            }
        }
    }

    if (dp[n] < 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << dp[n] << "\n";

    // Reconstruct path
    vector<int> path;
    for (int cur = n; cur != -1; cur = parent[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());

    for (int x : path) cout << x << " ";
    cout << "\n";
}
