#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int n, m, T, t, q;

double a[qwe];

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> a[i];
        a[i] /= 100;
    }
    return 0;
}