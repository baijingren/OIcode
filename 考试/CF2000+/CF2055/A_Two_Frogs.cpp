#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int T;
int n, m;
int a, b;
char c[qwe];
int main(){
    cin >> T;
    while(T--){
        cin >> n >> a >> b;
        if(abs(b - a - 1) % 2 == 1){
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
    return 0;
}