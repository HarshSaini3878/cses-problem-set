#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> color(n + 1, 0); // 0 = uncolored, 1 or 2 = team

    for (int start = 1; start <= n; start++) {
        if (color[start] == 0) {
            // BFS to color this component
            queue<int> q;
            q.push(start);
            color[start] = 1;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (color[v] == 0) {
                        // assign opposite team
                        color[v] = (color[u] == 1 ? 2 : 1);
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        // conflict => not bipartite
                        cout << "IMPOSSIBLE\n";
                        return 0;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << color[i] << " ";
    }
    cout << "\n";

    return 0;
}
