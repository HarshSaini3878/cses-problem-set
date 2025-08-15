#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    for (long long k = 1; k <= n; k++) {
        long long total_pairs = (k * k) * (k * k - 1)/2; // total pairs
        long long attacking_pairs = 4 * (k - 1) * (k - 2);
        cout << total_pairs - attacking_pairs << "\n";
    }
}
/*
Logic for Two Knights Problem (CSES):

1. Total ways to place two knights on an n×n board:
   - Number of squares = n^2
   - Choose any 2 squares = C(n^2, 2) = n^2 * (n^2 - 1) / 2

2. Ways in which two knights attack each other:
   - A knight moves in an L-shape (2 in one direction, 1 in the perpendicular).
   - Two knights attack each other if they form such a move.
   - On an n×n board:
        * There are (n - 1) * (n - 2) positions for a 2×3 rectangle where knights can attack.
        * Each rectangle has 2 attacking arrangements (both directions).
        * There are two orientations (2×3 and 3×2).
   - Total attacking pairs = 4 * (n - 1) * (n - 2)

3. Non-attacking pairs:
   - non_attacking = total_pairs - attacking_pairs
   - non_attacking = [n^2 * (n^2 - 1) / 2] - [4 * (n - 1) * (n - 2)]

4. Special case:
   - For n = 1 → result = 0 (can't place two knights)
   - Formula works for n ≥ 2
*/
