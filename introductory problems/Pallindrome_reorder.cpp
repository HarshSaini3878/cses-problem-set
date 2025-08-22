#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;

    cin>>s;
    unordered_map<char,int>mp;
    for(auto it:s)mp[it]++;
    int count=0;
    char mid;
    for(auto it:mp){
        if(it.second%2==1){
            if(count==1){
                cout<<"NO SOLUTION"<<endl;
                return 0;
            }else{
                count++;
                mid=it.first;
            }
        }
    }
    string ans="";
    for(auto it:mp){
        int freq=floor(it.second/2.0);
        while(freq--)ans.push_back(it.first);

    }
    string x=ans;
    reverse(x.begin(),x.end());
    if(count==0){
        cout<<ans+x<<endl;
    }else{
        cout<<ans+mid+x<<endl;
    }
    
    return 0;
}