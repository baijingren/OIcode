#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
typedef long long ll;
int T, n;
ll a[qwe];
int main(){
    cin >> T;
    while(T--){
        cin >> n;
        if(n == 2){
            cout << -1 << endl;
        }
        else if(n == 1){
            cout << 1 << endl;
        }
        else if(n == 3){
            cout << 1 << ' '  << 2 << ' ' << 3 << endl;
        }
        else{
            a[1] = 1;
            a[2] = 2;
            a[3] = 3;
            for(int i = 4; i <= n; i++){
                a[i] = a[i - 1] * 2;
            }
            for(int i = 1; i<= n; i++){
                cout << a[i] << ' ';
            }
            cout << endl;
        }
    }
}