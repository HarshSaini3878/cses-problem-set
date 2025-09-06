#include <bits/stdc++.h>
using namespace std;
/// DJIKISTRA ALGO TC: o((E+V)LOGV)
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;
    cin >> n>>m;
    unordered_map<ll,vector<pair<ll,ll>>>mp;
    for(ll i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        mp[a].push_back({b,c});
    }
    vector<ll>dist(n+1,LLONG_MAX);
    
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    dist[1]=0;
    pq.push({0,1});
    while(pq.size()){
        auto [w,node]=pq.top();
        pq.pop();
        if (w > dist[node]) continue; 

        for(auto [ngb,d]:mp[node]){
            if(dist[ngb]>d+dist[node]){
              
                dist[ngb]=d+dist[node];
                pq.push({dist[ngb],ngb});
            }
        }
    }

    for(ll i=1;i<dist.size();i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}