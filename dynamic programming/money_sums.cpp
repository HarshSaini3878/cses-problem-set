// #include <bits/stdc++.h>
// using namespace std;

// unordered_map<long long,bool> dp;
// set<int> st;  // sorted automatically

// bool f(int i, vector<int>& nums, int curr) {
//     if (i == nums.size()) {
//         if (curr != 0) st.insert(curr);
//         return true;
//     }

//     long long key = ((long long)i << 32) ^ (curr + 1000000000LL); 
//     if (dp.find(key) != dp.end()) return dp[key];

//     f(i + 1, nums, curr);            // skip
//     f(i + 1, nums, curr + nums[i]);  // take

//     return dp[key] = true;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     cin >> n;
//     vector<int> nums(n);
//     for (int i = 0; i < n; i++) cin >> nums[i];

//     f(0, nums, 0);

//     cout << st.size() << "\n";
//     for (int x : st) cout << x << " ";
//     cout << "\n";
// }
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n);
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        total += nums[i];
    }

    
    vector<char> dp(total + 1, 0);
    dp[0] = 1; 

    for (int num : nums) {
        
        for (int s = total; s >= 0; s--) {
            if (dp[s]) dp[s + num] = 1;
        }
    }

    vector<int> results;
    for (int s = 1; s <= total; s++) { // skip 0
        if (dp[s]) results.push_back(s);
    }

    cout << results.size() << "\n";
    for (int x : results) cout << x << " ";
    cout << "\n";
}
