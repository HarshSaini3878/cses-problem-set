#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,k;
    cin >> n>>k;
    ll x,a,b,c;
    cin>>x>>a>>b>>c;
    vector<ll>v(n);
    v[0]=x;
    for(ll i=1;i<n;i++){
        v[i]=(a*v[i-1]+b) %c;
    }
     ll sum=0;
     ll ans=0;
     for(ll i=0;i<k;i++){
        sum+=v[i];
     }
     ans^=sum;
     for(ll i=k;i<n;i++){
        sum-=v[i-k];
        sum+=v[i];
         ans^=sum;
     }
     cout<<ans<<endl;
    
    return 0;
}