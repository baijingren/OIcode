#include<bits/stdc++.h>
using namespace std;
const int qwe = 1005;
int n, q;
int a[qwe];
int md[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
int main()
{

    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    int l = 0, num = 0;
    bool TU = false;
    for (int i = 1; i <= q; i++)
    {
        TU = false;
        scanf("%d %d", &l, &num);
        for(int j = 1;j <= n;j++)
        {
            if(a[j] % md[l] == num)
            {
                printf("%d\n", a[j]);
                TU = true;
                break;
            }
        }
        if(TU == false)
        {
            printf("-1\n");
        }
    }
    return 0;
}