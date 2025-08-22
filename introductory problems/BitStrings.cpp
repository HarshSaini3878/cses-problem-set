#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    long long ans=1;
    const int mod=1e9+7;
    for(ll i=1;i<=n;i++){
       ans=(ans*2)%mod;
    }
    cout<<ans<<endl;
    return 0;
}