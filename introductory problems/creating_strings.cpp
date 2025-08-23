#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector<ll> factorial;

void computeFactorial(int n) {
    factorial.resize(n + 1, 0);
    factorial[0] = 1;
    for (int i = 1; i <= n; i++) {
        factorial[i] = i * factorial[i - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    computeFactorial(n);

  
    unordered_map<char, int> freq;
    for (auto c : s) freq[c]++;

    long long total = factorial[n];
    for (auto &it : freq) {
        if (it.second > 1) total /= factorial[it.second];
    }

    cout << total << "\n";


    sort(s.begin(), s.end());
    do {
        cout << s << "\n";
    } while (next_permutation(s.begin(), s.end()));

    return 0;
}
