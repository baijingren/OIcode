#include <bits/stdc++.h>
using namespace std;
int m, n;
string s;

int main(){
    cin >> n;
    if(n % 2 == 1){
        for(int i = 1; i <= n / 2; i++){
            cout << '-';
        }
        cout << '=';
        for(int i = 1; i <= n / 2; i++){
            cout << '-';
        }
        cout << '\n';
        return 0;
    }
    else{
        for(int i = 1; i <= (n - 1) / 2; i++){
            cout << '-';
        }
        cout << "==";
        for(int i = 1; i <= (n - 1) / 2; i++){
            cout << '-';
        }
        cout << '\n';
        return 0;
    }
    return 0;
}