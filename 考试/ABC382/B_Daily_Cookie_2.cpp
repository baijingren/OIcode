#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int n, m, T, t, q;
string s;

int d;

int main(){
    cin >> n >> d;
    cin >> s;
    for(int i = 0; i < n; i++){
        if(s[i] == '.'){
            t ++;
        }
    }
    q = n - t - d;
    // cerr << q;
    for(int i = 0; i < n; i++){
        if(s[i] == '@' && q){
            q--;
            cout << '@';
        }
        else{
            cout << '.';
        }
    }
    cout << endl;
    // cout << t + d << endl;
    return 0;

}