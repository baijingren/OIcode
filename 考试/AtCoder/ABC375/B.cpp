#include<bits/stdc++.h>
using namespace std;
const int qwe= 1e6+5;
int n;
double a[qwe], b[qwe];
double ans = 0;
double pw2(double a){
    return a * a;
}
int main(){
    cin>>n;
    for(int i = 1; i<=n;i++){
        cin>>a[i]>>b[i];
    }
    a[++n] = 0, b[n] = 0;
    for(int i = 1;i <= n; i++){
        ans += sqrt(pw2(a[i] - a[i - 1]) + pw2(b[i] - b[i - 1]));
    }
    printf("%.10lf",ans);
    return 0;
}