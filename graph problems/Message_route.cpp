#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a); // if graph is undirected, else remove this line
    }

    vector<ll> parent(n + 1, -1);
    vector<bool> visited(n + 1, false);

    queue<ll> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        ll u = q.front();
        q.pop();

        if (u == n) {
            // reconstruct path
            vector<ll> path;
            for (ll cur = n; cur != -1; cur = parent[cur]) {
                path.push_back(cur);
            }
            reverse(path.begin(), path.end());

            cout << path.size() << "\n";
            for (ll node : path) cout << node << " ";
            cout << "\n";
            return 0;
        }

        for (ll v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
