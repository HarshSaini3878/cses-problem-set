#include <bits/stdc++.h>
using namespace std;

#define ll long long
int mod =1e9+7;
int dp[1002][1002];
int f(vector<vector<char>>&matrix,int i,int j,int n){
    if(i==n-1 and j==n-1) return 1;
    if(i==n or j==n or j<0 or i<0 or matrix[i][j]=='*') return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int down=f(matrix,i+1,j,n);
    int up=f(matrix,i,j+1,n);
    return dp[i][j]=( up%mod +down%mod)%mod;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp,-1,sizeof dp);
    int  n;
    cin >> n;
    vector<vector<char>>matrix;
    for(ll i=0;i<n;i++){
        vector<char>v;
        for(ll j=0;j<n;j++){
            char x;
            cin>>x;
            v.push_back(x);
        }
        matrix.push_back(v);
    }
    if(matrix[0][0]=='*' or matrix[n-1][n-1]=='*'){
        cout<<0<<endl;
        return 0;
    }
    cout<<f(matrix,0,0,n);
    return 0;
}