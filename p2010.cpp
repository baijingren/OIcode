#include<bits/stdc++.h>
using namespace std;
int dta, dtb;
int ans;
int a[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d", &dta, &dtb);
    for (int i = 1; i <= 12;i++)
    {
        for (int j = 1; j <= a[i];j++)
        {
            x = i * 100 + j;
        }
    }
    printf("%d", ans);
    return 0;
}