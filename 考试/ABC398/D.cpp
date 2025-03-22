#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int n, r, t;
int x, y, cnt;
char c[qwe];
bool ans[qwe];
int main(){
    cin >> n >> r >> t;
    for(int i = 1; i <= n; i++){
        cin >> c[i];
        if(c[i] == 'N'){
        }
        else if(c[i] == 'S'){
        }
        else if(c[i] == 'E'){
        }
        else if(c[i] == 'W'){
        }
        if(r == 0 && t == 0){
            ans[i] = 1;
        }
        else{
            ans[i] = 0;
        }
        cnt++;
    }
    for(int i = 1; i <= n; i++){
        cout << (int)ans[i];
    }
    cout << endl;
    return 0;
}