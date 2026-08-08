#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e2 +5;
int n, m;
int a[qwe][qwe], cntRow[qwe], cntCol[qwe];
int main(){
    for(int i = 1; i <= 8; i++){
        for(int j = 1; j <= 8; j ++){
            char c;
            cin >> c;
            if(c == '#'){
                cntCol[j]++;
                cntRow[i]++;
                a[i][j] = 1;
            }
            else if(c == '.'){
                a[i][j] = 0;
            }
        }
    }
    int cnta = 0, cntb = 0;
    for(int i = 1; i <= 8; i ++){
        if(cntCol[i] == 0){
            cnta ++ ;
        }
        if(cntRow[i] == 0){
            cntb++;
        }
    }
    cout << cnta * cntb << endl;
    return 0;
}