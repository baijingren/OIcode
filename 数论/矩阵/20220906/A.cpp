#include<bits/stdc++.h>
using namespace std;
const int qwe=205;
int n,m,p;
struct Matrix{
    int n,m;
    int a[qwe][qwe];
    Matrix operator*(const Matrix &a) const {
        Matrix ans;
        ans.n=n;
        ans.m=a.m;
        for(int i=1;i<=n;i++){
            for(int i=1;i<=m)
        }
    }
} a,b;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>m>>p;
    a.n=m;
    a.m=p;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=p;j++){
            cin>>a.a[i][j];
        }
    }
    cin>>p>>n;
    a.n=p;
    a.m=n;
    for(int i=1;i<=p;i++){
        for(int j=1;j<=n;j++){
            cin>>b.a[i][j];
        }
    }
}