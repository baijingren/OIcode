#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int T;
int n, m;
int a[qwe] ,b[qwe], s[qwe];
int main(){
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        int mn = INT_MAX, mx = 0, cnt = 0;
        for(int i = 1; i <= n; i++){
            cin >> b[i];
            s[i] = a[i] - b[i];
            if(s[i] >= 0){
                mn = min(s[i], mn);
            }
        }
        for(int i = 1; i <= n; i++){
            if(s[i] < 0){
                cnt++;
                mx += -s[i];
            }
        }
        if(cnt >= 2){
            cout << "NO\n";
        }
        else if(cnt == 0){
            cout << "YES\n";
        }
        else if(cnt == 1){
            if(mx <= mn){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }
    return 0;
}