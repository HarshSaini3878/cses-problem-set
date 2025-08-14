#include<bits/stdc++.h>
using namespace std;
int main(){
long long n;
cin>>n;
vector<long long>v;
while(n!=1){
    v.push_back(n);
    if(n%2==0){
         n/=2;
    }else{
     n=n*3+1;
    }
}
v.push_back(n);
for(auto it:v) cout<<it<<" ";
return 0;
}
