#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool f(int a ,int b){
    if ((a + b) % 3 != 0) return false;
    int mx = max(a, b);
    int mn = min(a, b);
    return mx <= 2 * mn;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << (f(a, b) ? "YES" : "NO") << "\n";
    }
    return 0;
}
