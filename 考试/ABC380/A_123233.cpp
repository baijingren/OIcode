#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int T, m ,n, q, t;
int a[qwe];
string s;

int main(){
    cin >> n;
    while(n){
        m = n % 10;
        a[m]++;
        n /= 10;
    }
    if(a[1] == 1 && a[2] == 2 && a[3] == 3){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}