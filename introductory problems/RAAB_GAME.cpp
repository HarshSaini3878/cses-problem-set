#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(int n, int a, int b) {
    if(a + b > n) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";

    vector<int> A, B;
    int low = 1, high = n;

    // Give wins to A
    for(int i=0; i<a; i++) {
        A.push_back(high);
        B.push_back(low);
        high--; low++;
    }

    // Give wins to B
    for(int i=0; i<b; i++) {
        A.push_back(low);
        B.push_back(high);
        low++; high--;
    }

    // Ties
    while(low <= high) {
        A.push_back(low);
        B.push_back(low);
        low++;
    }

    for(int x : A) cout << x << " ";
    cout << "\n";
    for(int x : B) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--) {
        int n, a, b;   // ✅ order fixed
        cin >> n >> a >> b;
        solve(n, a, b);
    }
    return 0;
}
