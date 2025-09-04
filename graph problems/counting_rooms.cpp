#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector<pair<int,int>>dir={{0,-1},{-1,0},{1,0},{0,1}};
void dfs(vector<vector<char>>&grid,int i,int j){
    if(i<0 or j<0 or j==grid[0].size() or i==grid.size()) return ;
    grid[i][j]='*';
    for(auto it:dir){
     int nx=it.first+i;
     int ny=it.second+j;
     if(nx>=0 and ny>=0 and ny<grid[0].size() and nx<grid.size() and grid[nx][ny]=='.'){
        dfs(grid,nx,ny);
     }
    }

}
int f(vector<vector<char>>&grid,int n,int m){
    int count=0;
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='.'){
                count++;
                dfs(grid,i,j);
            }
        }
    }
    return count;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;
    cin >> n>>m;
    vector<vector<char>>grid(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
             cin>>grid[i][j];
        }
    }
    cout<<f(grid,n,m)<<endl;
    
    return 0;
}