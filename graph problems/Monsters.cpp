#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int rows, cols;
    cin >> rows >> cols;

    vector<vector<char>> grid(rows, vector<char>(cols));
    queue<pair<int,int>> monster, human;

    pair<int,int> start;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin >> grid[i][j];
            if(grid[i][j]=='A'){
                human.push({i,j});
                start={i,j};
            }
            if(grid[i][j]=='M') monster.push({i,j});
        }
    }

    vector<pair<int,int>> dir={{0,-1},{-1,0},{1,0},{0,1}};
    vector<char> dchar={'L','U','D','R'}; // mapping moves
    vector<vector<bool>> visited(rows, vector<bool>(cols,false));
    vector<vector<pair<int,int>>> parent(rows, vector<pair<int,int>>(cols, {-1,-1}));
    vector<vector<char>> moveDir(rows, vector<char>(cols, 0));

    visited[start.first][start.second]=true;

    int steps=0;
    while(!human.empty()){
        // Spread monsters
        int ms = monster.size();
        while(ms--){
            auto [x,y] = monster.front(); monster.pop();
            for(auto [dx,dy]:dir){
                int nx=x+dx, ny=y+dy;
                if(nx>=0 && ny>=0 && nx<rows && ny<cols && grid[nx][ny]=='.'){
                    grid[nx][ny]='M';
                    monster.push({nx,ny});
                }
            }
        }

        // Human moves
        int hs = human.size();
        while(hs--){
            auto [x,y] = human.front(); human.pop();

            if(x==0 || y==0 || x==rows-1 || y==cols-1){
                cout << "YES\n";
                cout << steps << "\n";

                // Reconstruct path
                string path="";
                while(!(x==start.first && y==start.second)){
                    path.push_back(moveDir[x][y]);
                    auto p=parent[x][y];
                    x=p.first; y=p.second;
                }
                reverse(path.begin(), path.end());
                cout << path << "\n";
                return 0;
            }

            for(int k=0;k<4;k++){
                int nx=x+dir[k].first, ny=y+dir[k].second;
                if(nx>=0 && ny>=0 && nx<rows && ny<cols && grid[nx][ny]=='.' && !visited[nx][ny]){
                    visited[nx][ny]=true;
                    parent[nx][ny]={x,y};
                    moveDir[nx][ny]=dchar[k];
                    human.push({nx,ny});
                }
            }
        }
        steps++;
    }

    cout << "NO\n";
    return 0;
}
