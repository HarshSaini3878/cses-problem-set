#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    ll sum = 1LL * n * (n + 1) / 2;

    if (sum % 2 != 0) {
        cout << 0 << "\n";
        return 0;
    }

    int target = sum / 2;
    vector<int> dp(target + 1, 0);
    dp[0] = 1; 

    for (int num = 1; num <= n; num++) {
        for (int s = target; s >= num; s--) {
            dp[s] = (dp[s] + dp[s - num]) % MOD;
        }
    }

 
    ll inv2 = (MOD + 1) / 2; 
    cout << (1LL * dp[target] * inv2) % MOD << "\n";

    return 0;
}
