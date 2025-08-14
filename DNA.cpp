#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin>>s;
    int i=0;
    int j=0;
    int n=s.size();
    int mx=-1;
    while(j<n){
        while(j<n and s[i]==s[j] )j++;
        mx=max(mx,j-i);
        i=j;
    }
cout<<mx<<endl;
    
    return 0;
}