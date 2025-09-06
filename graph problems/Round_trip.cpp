#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> parent, visited;

vector<int> cycle;

bool dfs(int u, int p) {
    visited[u] = 1;
    parent[u] = p;
    for (int v : adj[u]) {
        if (v == p) continue; // ignore the edge to parent
        if (!visited[v]) {
            if (dfs(v, u)) return true;
        } else {
            // Found a cycle (v is already visited, and not parent)
            cycle.push_back(v);
            int cur = u;
            while (cur != v) {
                cycle.push_back(cur);
                cur = parent[cur];
            }
            cycle.push_back(v); // close the cycle
            reverse(cycle.begin(), cycle.end());
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    adj.assign(n + 1, {});
    parent.assign(n + 1, -1);
    visited.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                cout << cycle.size() << "\n";
                for (int x : cycle) cout << x << " ";
                cout << "\n";
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
