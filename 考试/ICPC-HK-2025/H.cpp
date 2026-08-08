#include <bits/stdc++.h>
using namespace std;
int T;
string s;
int main(){
    cin >> T;
    while(T--){
        cin >> s;
        bool flag = 0;
        for(int i = 0; i < s.length() - 1; i++){
            if(s[i] == s[i + 1]){
                cout << s.length() - 1 << endl;
                flag = 1;
                break;
            }
        }
        if(!flag){
            cout << s.length() - 2 << endl;
        }
    }
}