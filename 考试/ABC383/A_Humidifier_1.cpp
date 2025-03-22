#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int T, n, m;
int t[qwe], v[qwe];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> t[i] >> v[i];
        m -= (t[i] - t[i - 1]);
        m = max(0, m);
        m += v[i];
    }
    cout << m << endl;
    return 0;
}