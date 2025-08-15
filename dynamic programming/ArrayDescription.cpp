// #include <bits/stdc++.h>
// using namespace std;

// const int MOD = 1e9 + 7;
// int n, m;
// vector<int> v;
// vector<vector<int>> dp;

// int f(int i, int prev) {
//     if (i == n) return 1; 
//     if (dp[i][prev] != -1) return dp[i][prev];

//     long long ans = 0;

//     if (v[i] != 0) {
//         if (prev == 0 || abs(v[i] - prev) <= 1) {
//             ans = f(i + 1, v[i]);
//         }
//     } else {
//         for (int val = 1; val <= m; val++) {
//             if (prev == 0 || abs(val - prev) <= 1) {
//                 ans += f(i + 1, val);
//                 if (ans >= MOD) ans -= MOD;
//             }
//         }
//     }

//     return dp[i][prev] = ans;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     cin >> n >> m;
//     v.resize(n);
//     for (int i = 0; i < n; i++) cin >> v[i];

//     dp.assign(n, vector<int>(m + 1, -1));




//     cout << f(0, 0) % MOD << "\n";
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<vector<int>> dp(n, vector<int>(m + 2, 0)); 
    // m+2 so we can safely access val-1 and val+1 without bound checks

    // Base case
    if (v[0] != 0) {
        dp[0][v[0]] = 1;
    } else {
        for (int val = 1; val <= m; val++) dp[0][val] = 1;
    }

    // Build table
    for (int i = 1; i < n; i++) {
        if (v[i] != 0) {
            int val = v[i];
            dp[i][val] = ((long long)dp[i-1][val] + dp[i-1][val-1] + dp[i-1][val+1]) % MOD;
        } else {
            for (int val = 1; val <= m; val++) {
                dp[i][val] = ((long long)dp[i-1][val] + dp[i-1][val-1] + dp[i-1][val+1]) % MOD;
            }
        }
    }

    // Answer
    long long ans = 0;
    for (int val = 1; val <= m; val++) {
        ans += dp[n-1][val];
        if (ans >= MOD) ans -= MOD;
    }

    cout << ans << "\n";
}
