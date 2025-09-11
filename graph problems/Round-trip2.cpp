#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> parent, visited, inrec;
vector<int> cycle;

bool dfs(int u) {
    visited[u] = 1;
    inrec[u] = 1;
    for (int v : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;
            if (dfs(v)) return true;
        } else if (inrec[v]) {
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
    inrec[u] = 0;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    adj.assign(n + 1, {});
    parent.assign(n + 1, -1);
    visited.assign(n + 1, 0);
    inrec.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i)) {
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
