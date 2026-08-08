#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e3+5;
int T, n, m;
int a[qwe];
int b[qwe][qwe];
string s;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i < j && a[i] < a[j]){
                b[a[i]][a[j]] = b[a[j]][a[i]] = 1;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << b[i][j];
        }
        cout << endl;
    }
    return 0;
}