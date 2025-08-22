#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int total = 1 << n; 

    for (int i = 0; i < total; i++) {
        int g = i ^ (i >> 1); 

        
        string s = bitset<32>(g).to_string();  
        cout << s.substr(32 - n) << "\n"; 
    }

    return 0;
}
