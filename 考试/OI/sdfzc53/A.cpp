#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6 + 5;
int n;
long long ans;
int c[qwe], p[qwe];
queue<int> q;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &c[i]);
        c[i + n] = c[i];
    }
    for(int i=2*n;i>=1;i--){
        
    }
    printf("%lld", ans);
}