#include <bits/stdc++.h>
using namespace std;

#define ll long long

// int dp[20000][20000];

// int f(ll prev,vector<ll>&nums,ll i){
//     if(i==nums.size()) return 0;
//     int leave=f(prev,nums,i+1);
//     int take=0;
//     if(dp[i][prev+1]!=-1) return dp[i][prev+1]!=-1;
//     if(prev==-1 or nums[i]>nums[prev]){
//         take=f(nums[i],nums,i+1)+1;
//     }
//     return dp[i][prev+1]=max(take,leave);
// }
int LIS(vector<ll>& nums) {
    vector<ll> lis;
    for (ll x : nums) {
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if (it == lis.end()) lis.push_back(x);
        else *it = x;
    }
    return lis.size();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll>nums(n,0);
    for(ll i=0;i<n;i++)cin>>nums[i];
    
    cout<<LIS(nums)<<endl;
    return 0;
}
