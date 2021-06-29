#include<bits/stdc++.h>
using namespace std;
const int qwe = 505;
int a[qwe][qwe];
int main()
{
    freopen("/home/bai/code/test.in", "r", stdin);
    freopen("/home/bai/code/test.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 2; i <= n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            if(i == j)
            {
                continue;
            }
            scanf("%d", &a[i][j]);
            a[j][i] = a[i][j];
        }
    }
    for(int i = 1; i <= n; i++)
    {
        
    }
    return 0;
}
