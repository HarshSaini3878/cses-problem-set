#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<int>> adj(n+1);
    vector<int> indeg(n+1, 0);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
    }

    // Kahn topo sort
    queue<int> q;
    for (int i = 1; i <= n; ++i) if (indeg[i] == 0) q.push(i);

    vector<int> topo;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (int v : adj[u]) {
            if (--indeg[v] == 0) q.push(v);
        }
    }

    // optional sanity check:
    // if (topo.size() != (size_t)n) { /* graph has a cycle — should not happen */ }

    vector<ll> dp(n+1, 0);
    dp[1] = 1; // one way to be at start

    for (int u : topo) {
        if (dp[u] == 0) continue;
        for (int v : adj[u]) {
            dp[v] += dp[u];
            if (dp[v] >= MOD) dp[v] -= MOD;
        }
    }

    cout << dp[n] % MOD << '\n';
    return 0;
}
