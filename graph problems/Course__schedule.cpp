#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;
    cin >> n>>m;
    unordered_map<int,vector<int>>mp;
    vector<int>indegree(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);
        indegree[b]++;


    }
    vector<int>topo;
    queue<int>q;
    for(int i=1;i<indegree.size();i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(q.size()){
        auto it=q.front();
        q.pop();
        topo.push_back(it);
        for(auto ngb:mp[it]){
            indegree[ngb]--;
            if(indegree[ngb]==0) q.push(ngb);
        }
    }
    if(topo.size()!=n) {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    for(auto it:topo){
        cout<<it<<" ";
    }


    
    return 0;
}