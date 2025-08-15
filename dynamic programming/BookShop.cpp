#include <bits/stdc++.h>
using namespace std;

int dp[1001][100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> books(n), pages(n);
    for (int i = 0; i < n; i++) cin >> books[i];
    for (int i = 0; i < n; i++) cin >> pages[i];

    
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= x; j++) {
            int take = 0;
            int leave = dp[i + 1][j]; 
            if (j >= books[i]) take = pages[i] + dp[i + 1][j - books[i]];
            dp[i][j] = max(leave, take);
        }
    }

    cout << dp[0][x] << "\n";
    return 0;
}
