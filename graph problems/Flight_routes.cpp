#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int,int>>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    // min-heap: (cost, node)
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push({0, 1});

    vector<int> cnt(n+1, 0);
    vector<ll> ans;

    while (!pq.empty() && (int)ans.size() < k) {
        auto [cost, node] = pq.top();
        pq.pop();

        cnt[node]++;

        if (node == n) {
            ans.push_back(cost);
        }
        if (cnt[node] > k) continue; // expand at most k times

        for (auto [ngb, wt] : adj[node]) {
            pq.push({cost + wt, ngb});
        }
    }

    for (ll x : ans) cout << x << " ";
    cout << "\n";

    return 0;
}
