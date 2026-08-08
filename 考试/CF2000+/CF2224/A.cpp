#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int qwe = 1e6+5;
int T;
int n;
ll a[qwe];
int main(){
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = n - 1; i >= 1; i--){
            if(a[i + 1] > 0){
                a[i] += a[i + 1];
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(a[i] > 0){
                ans ++;
            }
        }
        cout << ans << endl;
    }
}