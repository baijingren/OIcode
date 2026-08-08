#include<bits/stdc++.h>
using namespace std;
int n;
int a[25] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576};
int main()
{
    freopen("/home/bai/code/test.in", "r", stdin);
    freopen("/home/bai/code/test.out", "w", stdout);
    scanf("%d", &n);
    // for (int i = 1; i <= n; i++)
    // {
        // scanf("%d", )
    // }
    if(n % 2 == 1)
    {
        printf("-1");
        return 0;
    }
    int A = n;
    for (int i = 1; i <= n; i++)
    {
        // if(A == 1)
        // {
        //     return 0;
        // }
        if(A >= a[i])
        {
            A %= a[i];
            printf("%d ", a[i]);
        }
    }
    return 0;
}