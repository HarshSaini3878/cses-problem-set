#include <bits/stdc++.h>
using namespace std;

#define ll long long


class dsu{
public:
   int n;
   vector<int>parent;
   dsu(int size){
    n=size;
    parent.resize(n+1,0);
    iota(parent.begin(),parent.end(),0);
    parent[0]=-1;
   }
   int find(int a){
    if(parent[a]==a) return a;
    return parent[a]=find(parent[a]);

   }
   bool unite(int a ,int b){
    int x=find(a);
    int y=find(b);
    if(x==y) return true;
    parent[x]=y;
    return true;
   }

};



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;
    cin >> n>>m;
    
  dsu DSU(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    DSU.unite(a,b);
  }
  vector<int>v;
  for(int i=1;i<DSU.parent.size();i++){
    if(DSU.parent[i]==i){
        v.push_back(i);
    }
  }
  if(v.size()==0){
    cout<<0<<endl;
    return 0;
  }
  cout<<v.size()-1<<endl;
  for(int i=0;i<v.size()-1;i++){
    cout<<v[i]<<" "<<v[i+1]<<endl;
  }
    
    return 0;
}