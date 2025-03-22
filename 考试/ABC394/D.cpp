#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int n;
string s;
stack<char> m;
int main(){
    cin >> s;
    n = s.length();
    for(int i = 0; i < n; i++){
        if(s[i] == ')'){
            if(!m.empty() && m.top() == '('){
                m.pop();
            }
            else{
                cout << "No";
                return 0;
            }
        }
        else if(s[i] == ']'){
            if( !m.empty() && m.top() == '['){
                m.pop();
            }
            else{
                cout << "No";
                return 0;
            }
        }
        else if(s[i] == '>'){
            if(!m.empty() && m.top() == '<'){
                m.pop();
            }
            else{
                cout << "No";
                return 0;
            }
        }
        else{
            m.push(s[i]);
        }
    }
    if(m.size()){
        cout << "No";
        return 0;
    }
    cout << "Yes";
    return 0;
}