#include <bits/stdc++.h>
using namespace std;

void solve(int n, int from, int aux, int to, vector<pair<int,int>>& moves) {
    if (n == 0) return;
    solve(n - 1, from, to, aux, moves);   
    moves.push_back({from, to});          
    solve(n - 1, aux, from, to, moves);   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) return 0;

    vector<pair<int,int>> moves;
    moves.reserve((1u << n) - 1); 

    solve(n, 1, 2, 3, moves);

    cout << moves.size() << "\n";
    for (auto [a, b] : moves) cout << a << " " << b << "\n";
    return 0;
}
