#include <bits/stdc++.h>
using namespace std;

#define ll long long
int dp[1000005];
int f(int n){
    if(n==0)return 0;
    if(n<0) return INT_MAX-2;
    if(dp[n]!=-1) return dp[n];
    int x=n;
    int ans=INT_MAX-2;
    while(x!=0){
        int y=x%10;
        if(y!=0) ans=min(ans,1+f(n-y));
       
        x/=10;
    }
    return dp[n]=ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
memset(dp,-1,sizeof dp);
    int  n;
    cin >> n;
    
    cout<<f(n)<<endl;
    return 0;
}