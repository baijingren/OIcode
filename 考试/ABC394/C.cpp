#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int n;
string s;
int main(){
    cin >> s;
    n = s.length();
    for(int i = 0; i < n; i++){
        if(s[i] == 'A'){
            int j = i - 1;
            if(s[i - 1] != 'W'){
                continue;
            }
            while(j >= 0){
                if(s[j] != 'W'){
                    break;
                }
                j--;
            }
            j++;
            s[j] = 'A';
            j++;
            while(j <= i){
                s[j] = 'C';
                j++;
            }
        }
        // cerr << s << endl;
    }
    cout << s << endl;
    return 0;
}