#include<bits/stdc++.h>
using namespace std;
int T, n, m, r, c;
int a[505];
int main(){
    cin >> T;
    while(T--){
        cin >> n;
        if(n == 1 || n == 3){
            cout << "-1\n";
            continue;
        }
        else if(n == 2){
            cout << "66\n";
            continue;
        }
        a[1] = 6;
        a[2] = 6;
        a[3] = 3;
        a[4] = n % 2 == 1 ? 6 : 3;
        for(int i = 5; i <= n; i++){
            a[i] = 3;
        }
        for(int i = n; i >= 1; i--){
            cout<<a[i];
        }
        cout<<endl;
    }
    return 0;
}