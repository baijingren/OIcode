#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int n, k;
int a[qwe];
int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
            char c;
            cin >> c;
            switch (c) {
                case 'L':
                    a[i] = 0;
                    break;
                case 'R':
                    a[i] = 1;
                    break;
                default:
                    break;
            }
        }
        if(k * 2 > n){
            cout << -1 << endl;
            continue;
        }
        int cnt = 0;
        for(int i = 1; i <= k; i++){
            if(a[i] != 0){
                cnt++;
            }
            if(a[n - i + 1] != 1){
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}