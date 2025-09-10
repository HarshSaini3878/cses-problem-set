#include <bits/stdc++.h>
using namespace std;

#define ll long long
using tt = tuple<ll,int,int>; // cost, node, state

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n+1);

    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }

    // dist[node][state]
    vector<vector<ll>> dist(n+1, vector<ll>(2, LLONG_MAX));
    priority_queue<tt, vector<tt>, greater<tt>> pq;

    dist[1][0] = 0;
    pq.push({0,1,0});

    while(!pq.empty()){
        auto [cost,node,state] = pq.top();
        pq.pop();

        if(cost != dist[node][state]) continue;

        for(auto [ngb,wt] : adj[node]){
            // normal edge
            if(cost + wt < dist[ngb][state]){
                dist[ngb][state] = cost + wt;
                pq.push({dist[ngb][state], ngb, state});
            }
            // apply discount (only if not used yet)
            if(state == 0 && cost + wt/2 < dist[ngb][1]){
                dist[ngb][1] = cost + wt/2;
                pq.push({dist[ngb][1], ngb, 1});
            }
        }
    }

    cout << dist[n][1] << "\n";
    return 0;
}
