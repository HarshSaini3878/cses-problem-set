#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9+7;

int dp[1000006][2];

int f(int n) {
    // Base case:
    dp[1][0] = 1; // aligned (two vertical dominos)
    dp[1][1] = 1; // staggered (two horizontal dominos)

    for (int i = 2; i <= n; i++) {
        dp[i][0] = (4LL * dp[i-1][0] + dp[i-1][1]) % MOD;
        dp[i][1] = (2LL * dp[i-1][1] + dp[i-1][0]) % MOD;
    }

    return (dp[n][0] + dp[n][1]) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << f(n) << "\n";
    }

    return 0;
}
