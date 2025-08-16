#include <bits/stdc++.h>
using namespace std;

#define ll long long
int dp[5005][5005];
int f(string s,string t){
    for(int j=0;j<=t.size();j++)dp[s.size()][j]=t.size()-j;
    for(int i=0;i<=s.size();i++)dp[i][t.size()]=s.size()-i;
  for(int i=s.size()-1;i>=0;i--){
    for(int j=t.size()-1;j>=0;j--){
         if(s[i]==t[j])  dp[i][j]=dp[i+1][j+1];
         else  dp[i][j]=1+min( {dp[i+1][j+1],dp[i][j+1],dp[i+1][j]});
    }
  }
  return dp[0][0];
}
// int f(string s,string t,int i,int j){
//     if(i==s.size()) return t.size()-j;
//     if(j==t.size()) return s.size()-i;
//     if(dp[i][j]!=-1) return dp[i][j];
//     if(s[i]==t[j]) return dp[i][j]=f(s,t,i+1,j+1);
//     return dp[i][j]=1+min( {f(s,t,i+1,j) ,f(s,t,i,j+1),f(s,t,i+1,j+1)});
// }
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

   string s,t;
   cin>>s>>t;
   memset(dp,0,sizeof dp);
   cout<<f(s,t)<<endl;
    
    return 0;
}