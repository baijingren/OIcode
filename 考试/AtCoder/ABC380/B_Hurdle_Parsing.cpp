#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int T, m ,n, q, t;
int a[qwe];
string s;

int main(){
    cin >> s;
    n = s.length();
    for(int i = 1 ;i < n; i++){
        if(s[i] == '|'){
            cout << m << ' ';
            m = 0;
        }
        else{
            m++;
        }
    }
}