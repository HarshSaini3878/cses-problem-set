#include <bits/stdc++.h>
using namespace std;

#define ll long long

// directions: L, U, D, R
vector<pair<int,int>> dir = {{0,-1}, {-1,0}, {1,0}, {0,1}};
vector<char> moves = {'L', 'U', 'D', 'R'};

struct Node {
    int x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    Node start, endp;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') start = {i, j};
            if (grid[i][j] == 'B') endp = {i, j};
        }
    }

    // BFS setup
    queue<Node> q;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1,-1}));
    vector<vector<char>> moveDir(n, vector<char>(m, '?'));

    q.push(start);
    vis[start.x][start.y] = true;

    bool found = false;
    while (!q.empty()) {
        auto cur = q.front(); q.pop();

        if (cur.x == endp.x && cur.y == endp.y) {
            found = true;
            break;
        }

        for (int k = 0; k < 4; k++) {
            int nx = cur.x + dir[k].first;
            int ny = cur.y + dir[k].second;

            if (nx >= 0 && ny >= 0 && nx < n && ny < m && 
                !vis[nx][ny] && grid[nx][ny] != '#') 
            {
                vis[nx][ny] = true;
                q.push({nx, ny});
                parent[nx][ny] = {cur.x, cur.y};
                moveDir[nx][ny] = moves[k];
            }
        }
    }

    if (!found) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        // reconstruct path
        vector<char> path;
        Node cur = endp;
        while (!(cur.x == start.x && cur.y == start.y)) {
            path.push_back(moveDir[cur.x][cur.y]);
            cur = {parent[cur.x][cur.y].first, parent[cur.x][cur.y].second};
        }
        reverse(path.begin(), path.end());

        cout << path.size() << "\n";
        for (char c : path) cout << c;
        cout << "\n";
    }

    return 0;
}
