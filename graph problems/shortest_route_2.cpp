#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 1e15; // safe infinity

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, INF));

    
    for (ll i = 1; i <= n; i++) dist[i][i] = 0;

    for (ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }

   
    for (ll via = 1; via <= n; via++) {
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                if (dist[i][via] + dist[via][j] < dist[i][j]) {
                    dist[i][j] = dist[i][via] + dist[via][j];
                }
            }
        }
    }

   
    while (q--) {
        ll k, j;
        cin >> k >> j;
        if (dist[k][j] >= INF/2) cout << -1 << "\n";
        else cout << dist[k][j] << "\n";
    }

    return 0;
}
