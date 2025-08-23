#include <bits/stdc++.h>
using namespace std;

int ans = 0;

bool isSafe(int row, int col, vector<vector<char>>& board) {
    if (board[row][col] == '*') return false;

    
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') return false;
    }

   
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }

    
    for (int i = row, j = col; i >= 0 && j < 8; i--, j++) {
        if (board[i][j] == 'Q') return false;
    }

    return true;
}

void solve(int row, vector<vector<char>>& board) {
    if (row == 8) {
        ans++;
        return;
    }
    for (int col = 0; col < 8; col++) {
        if (isSafe(row, col, board)) {
            board[row][col] = 'Q';    
            solve(row + 1, board);
            board[row][col] = '.';   
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<char>> board(8, vector<char>(8));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> board[i][j];
        }
    }

    solve(0, board);
    cout << ans << "\n";
    return 0;
}
