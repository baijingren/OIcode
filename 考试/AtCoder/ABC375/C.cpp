#include<bits/stdc++.h>
using namespace std;
const int qwe = 3e3+5;
int n;
char c[qwe][qwe], ans[qwe][qwe];
// 5 * 5
/*
1,1 == 1,5
1,2 == 2,5
*/
int main(){
    cin>>n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin>>c[i][j];
        }
    }
    for(int i = 1; i <= n/2; i++){
        if(i % 4 == 0){
            for(int j = i; j <= n - i + 1; j++){
                ans[i][j] = c[i][j];
                ans[j][i] = c[j][i];
                ans[n - i + 1][j] = c[n - i + 1][j];
                ans[j][n - i + 1] = c[j][n - i + 1];
            }
        }
        if(i % 4 == 1){
            for(int j = i; j <= n - i + 1; j++){
                ans[j][n - i + 1] = c[i][j];
                ans[n - i + 1][n - j + 1] = c[j][n - i + 1];
                ans[n - j + 1][i] = c[n - i + 1][n - j + 1];
                ans[i][j] = c[n - j + 1][i];
            }
        }
        if(i % 4 == 2){
            for(int j = i; j <= n - i + 1; j++){
                ans[n - i + 1][n - j + 1] = c[i][j];
                ans[n - j + 1][i] = c[j][n - i + 1];
                ans[i][j] = c[n - i + 1][n - j + 1];
                ans[j][n - i + 1] = c[n - j + 1][i];
            }
        }
        if(i % 4 == 3){
            for(int j = i; j <= n - i + 1; j++){
                ans[n - j + 1][i] = c[i][j];
                ans[i][j] = c[j][n - i + 1];
                ans[j][n - i + 1] = c[n - i + 1][n - j + 1];
                ans[n - i + 1][n - j + 1] = c[n - j + 1][i];
            }
        }
    }
    for(int i = 1; i<= n; i++){
        for(int j = 1;j <= n; j++){
            cout<<ans[i][j];
        }
        cout<<'\n';
    }
    return 0;
}