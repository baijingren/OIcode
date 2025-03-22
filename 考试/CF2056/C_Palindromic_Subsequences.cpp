#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int T, n, m;
int a[qwe];
char c[qwe];
string s;
int main(){
    cin >> T;
    while(T--){
        cin >> n;
        if(n == 6){
            cout << "1 1 2 3 1 2" << endl;
            continue;
        }
        for(int i = 1; i < n - 1; i++){
            a[i] = i;
        }
        a[n - 1] = 1;
        a[n] = 2;
        for(int i = 1; i <= n; i++){
            cout << a[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}
/*
7
3
1 2 3 4 5 6 1
1 2 3 4 5 1 2
1 1 2 3 4 1 2

9
1 2 3 4 5 6 7 1 2


6
f(a) = 3
1 2 3 4 1 2
1 1 2 3 1 2

8
1 1 2 3 4 5 1 2
*/