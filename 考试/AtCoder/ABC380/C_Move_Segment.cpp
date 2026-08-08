#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int T, m ,n, q, t;
int a[qwe];
int b[qwe];
string s;

int main(){
    cin >> n >> m;
    cin >> s;
    if(s[0] == '1'){
        q++;
        a[q] = 0;
    }
    for(int i = 1; i < n; i++){
        
        if(s[i] == '1' && s[i - 1] == '0'){
            q++;
            a[q] = i;
        }
        if(s[i] == '0' && s[i - 1] == '1'){
            b[q] = i - a[q];
        }
    }
    if(s[n -1] == '1'){
        b[q] = n - a[q];
    }
    // cerr << a[m] << b[m];
    for(int i = 1; i <= b[m]; i++){
        s[a[m - 1] + b[m - 1] + i - 1] = '1';
        s[a[m] + i - 1] = '0';
    }
    cout << s;
}