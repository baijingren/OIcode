#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int T, n, m;
int a[qwe], b[qwe];
char c[qwe];
string s;
int main(){
    cin >> T;
    while(T--){
        cin >> n >> m;
        long long cnt = m * 4;
        cin >> a[1] >> b[1];
        for(int i = 2; i <= n; i++){
            cin >> a[i] >> b[i];
            cnt += m * 4 - ((m - a[i]) + (m - b[i])) * 2;
        }
        cout << cnt << endl;
    }
    return 0;
}