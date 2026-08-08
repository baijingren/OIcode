#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int n;
string s[qwe];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
    }
    sort(s + 1, s + n + 1, [](string a, string b){
        return a.length() < b.length();
    });
    for(int i = 1; i <= n; i++){
        cout << s[i];
    }
    return 0;
}