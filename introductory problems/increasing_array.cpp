#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    vector<long long>v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    long long ans=0;
    for(int i=0;i<n-1;i++){
        if(v[i]<=v[i+1])continue;
        ans+=v[i]-v[i+1];
        v[i+1]=v[i];
    }
    cout<<ans<<endl;
    
    return 0;
}