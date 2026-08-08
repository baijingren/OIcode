#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e7+5;
int n, m, T, t, q;
string s;

// int a[qwe], b[qwe];
int a[30][20];
int b[15];
int cnt = 1;

void dfs(int num, int t){
    // if(num == m && t)
    b[t] = num;
    if(t == n){
        for(int i = 1; i <= n; i++){
            cout << b[i] << ' ';
        }
        cout << endl;
        return;
    }
    // cerr << (num / 10) * 10 + ::t << endl;
    for(int i = num + 10; i <= ((num / 10) * 10 + 10 + ::t); i++){
        if(i > m){
            break;
        }
        dfs(i, t + 1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    t = (m % 10 == 0 ? 10 : m % 10);
    for(int i = 1; i <= t + n - 1 ;i++){
        a[i][0] = 1;
        for(int j = 1; j <= min(i, n); j++){
            if(i == j){
                a[i][j] = 1;
            }
            else
                a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
        }
    }
    cout << a[t + n - 1][n] << endl;
    for(int i = 1; i <= t; i++){
        dfs(i, 1);
    }
    return 0;
}