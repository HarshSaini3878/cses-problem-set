#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
int t;
cin>>t;
while(t--){
 ll x, y;
    cin >> x >> y;

    ll layer = max(x, y);
    ll ans;

    if (layer % 2 == 0) {
        // Even layer: starts bottom-left
        if (x == layer) {
            ans = layer * layer - (y - 1);
        } else {
            ans = (layer - 1) * (layer - 1) + x;
        }
    } else {
        // Odd layer: starts top-right
        if (y == layer) {
            ans = layer * layer - (x - 1);
        } else {
            ans = (layer - 1) * (layer - 1) + y;
        }
    }

    cout << ans << "\n";

}
   
    return 0;
}
