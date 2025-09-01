#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll f(vector<vector<ll>>& v, int idx, vector<ll>& dp) {
    if (idx == v.size()) return 0;
    if (dp[idx] != -1) return dp[idx];

    // Option 1: Skip
    ll leave = f(v, idx + 1, dp);

    // Option 2: Take + next non-overlapping
    auto it = upper_bound(
        v.begin(), v.end(),
        v[idx][1],
        [](ll value, const vector<ll>& row) {
            return value < row[0];
        }
    );
    int nextIdx = it - v.begin();
    ll take = v[idx][2] + f(v, nextIdx, dp);

    return dp[idx] = max(take, leave);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<ll>> v(n, vector<ll>(3));
    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2]; // start, end, profit
    }

    sort(v.begin(), v.end());

    vector<ll> dp(n, -1);
    cout << f(v, 0, dp) << "\n";
    return 0;
}
