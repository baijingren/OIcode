#include <bits/stdc++.h>
using namespace std;
string s;
int n, m;
int main(){
    cin >> s;
    n = s.length();
    for(int i = 0; i < n; i++){
        if(s[i] == '2'){
            m++;
        }
    }
    for(int i = 1; i <= m; i++){
        cout << 2;
    }
    return 0;
}