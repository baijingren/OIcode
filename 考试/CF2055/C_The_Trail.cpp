#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int qwe = 2e3+5;
int T;
int n, m;
ll a[qwe][qwe];
ll row[qwe], col[qwe];
char c[qwe];
int main(){
    cin >> T;
    while(T--){
        cin >> n >> m;
        memset(c, 0, sizeof(c));
        cin >> (c + 1);
        for(int i = 1; i <= max(n, m); i++){
            row[i] = col[i] = 0;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> a[i][j];
                row[i] += a[i][j]; // 行和
                col[j] += a[i][j]; // 列和
            }
        }
        int r = 1, l = 1;
        for(int i = 1; i <= n + m - 2; i++){
            if(c[i] == 'D'){
                a[r][l] = -row[r];
                row[r] += a[r][l];
                col[l] += a[r][l];
                r++;
            }
            else if(c[i] == 'R'){
                a[r][l] = -col[l];
                col[l] += a[r][l];
                row[r] += a[r][l];
                l++;
            }
        }
        a[n][m] = -row[n];
        row[n] += a[n][m];
        col[m] += a[n][m];
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cout << a[i][j] <<' ';
            }
            cout << '\n';
        }
    }
    return 0;
}