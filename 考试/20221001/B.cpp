#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
const int M=1e6+5;
int n,m;
int a[N][N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin>>a[i][j];
        }
    }
}