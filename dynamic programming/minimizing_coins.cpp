#include <bits/stdc++.h>
using namespace std;

#define ll long long
int dp[1000006];
int f(vector<int>&coins,int sum){
if(sum==0) return 0;
if(sum<0 ) return 1e7;
if(dp[sum]!=-1) return dp[sum];
int ans=1e7;
for(int i=0;i<coins.size();i++){
    if(sum< coins[i]) break;
    ans=min(ans,1+f(coins,sum-coins[i]));
}
return dp[sum]=ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
ll n,x;
cin>>n>>x;
vector<int>coins;
memset(dp,-1,sizeof dp);
while(n--){
    int y;
    cin>>y;
    coins.push_back(y);
}
sort(coins.begin(),coins.end());
int ans=f(coins,x);
   
if(ans==1e7){
    cout<<-1<<endl;
    return 0;
}
    cout<<ans<<endl;
    return 0;
}