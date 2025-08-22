#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> dp;

long long f(vector<int>& nums, int i, int j) {
    if (i == j) return nums[i];
    if (dp[i][j] != LLONG_MIN) return dp[i][j];

    long long takeLeft  = nums[i] - f(nums, i + 1, j);
    long long takeRight = nums[j] - f(nums, i, j - 1);

    return dp[i][j] = max(takeLeft, takeRight);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    dp.assign(n, vector<long long>(n, LLONG_MIN));

    long long diff = f(nums, 0, n - 1);
    long long total = accumulate(nums.begin(), nums.end(), 0LL);

    long long firstPlayer = (total + diff) / 2;
    cout << firstPlayer << "\n";
}
