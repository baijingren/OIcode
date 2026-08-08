#include <bits/stdc++.h>
using namespace std;
int n, m;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> m;
        for(int i = 2; i <= m; i++){
            cout << i << ' ';
        }
        cout << 1 << endl;
    }
}