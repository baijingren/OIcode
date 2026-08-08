#include<bits/stdc++.h>
using namespace std;
int a[30];
string s;
int main(){
    cin >> s;
    for(char c : s){
        a[c - 'A' + 1] ++;
    }
    if(a[1] == 1 && a[2] == 1 && a[3] == 1){
        cout << "Yes";
        return 0;
    }
    cout<<"No";
    return 0;
}