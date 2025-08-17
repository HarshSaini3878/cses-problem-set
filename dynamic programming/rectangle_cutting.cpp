#include <bits/stdc++.h>
using namespace std;

#define ll long long
int dp[505][505];
int f(int i,int j){
    if(i==j) return 0;
    // horizontal cuts
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=INT_MAX;
    for(int k=1;k<j;k++){
        ans=min(ans,f(i,j-k)+f(i,k)+1);
    }
    for(int k=1;k<i;k++){
        ans=min(ans,f(k,j)+f(i-k,j)+1);
    }
    return dp[i][j]=ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    memset(dp,-1,sizeof dp);
    cin>>n>>m;
    cout<<f(n,m)<<endl;
    
    return 0;
}