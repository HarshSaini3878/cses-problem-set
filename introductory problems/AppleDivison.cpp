#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    ll total = accumulate(p.begin(), p.end(), 0LL);
    ll ans = LLONG_MAX;

    int x = 1 << n;
    for (int mask = 0; mask < x; mask++) {
        ll sum = 0;
        for (int j = 0; j < n; j++) {
            if (mask & (1 << j)) {
                sum += p[j];
            }
        }
        ll diff = abs(total - 2 * sum);  
        ans = min(ans, diff);
    }

    cout << ans << "\n";
    return 0;
}
