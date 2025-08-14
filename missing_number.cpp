#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    vector<long long>v(n+1,-1);
    long long x=n-1;
    while(x--){
     long long  y;
     cin>>y;
     v[y]=y;

    }
    for(long long i=1;i<=n;i++){
         if(v[i]==-1){
            cout<<i<<endl;
            break;
         }
    }
    
    return 0;
}