#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

    // Base case: 1 way to make sum 0 (choose nothing)
    for (int i = 0; i <= n; i++) dp[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int sum = 0; sum <= x; sum++) {
            dp[i][sum] = dp[i - 1][sum]; // don't take coin i-1
            if (sum - coins[i - 1] >= 0) {
                dp[i][sum] += dp[i][sum - coins[i - 1]]; // take coin i-1 (unlimited times)
                if (dp[i][sum] >= MOD) dp[i][sum] -= MOD;
            }
        }
    }

    cout << dp[n][x] % MOD << "\n";
    return 0;
}
