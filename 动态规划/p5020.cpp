#include<bits/stdc++.h>
using namespace std;
const int qwe = 10005;
int T, n;
int a[qwe];
int main(){
    freopen("/home/bai/code/test.in", "r", stdin);
    freopen("/home/bai/code/test.out", "w", stdout);
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        sort(a + 1; a + n + 1);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                f[j] = max();
            }
        }
    }
    return 0;
}
