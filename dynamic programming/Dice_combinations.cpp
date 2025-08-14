#include <bits/stdc++.h>
using namespace std;
int dp[1000005];
#define ll long long
const int mod=1e9+7;
int f(int  n){
    if(n==0) return 1;
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];
    int ans=0;
    for(int i=1;i<=6;i++){
        ans=(ans%mod +f(n-i)%mod)%mod;
    }
    return dp[n]=ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
memset(dp,-1,sizeof dp);
    ll n;
    cin >> n;
    cout<< f(n)<<endl;
    return 0;
}