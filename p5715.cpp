#include<bits/stdc++.h>
using namespace std;
int a[5];
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a, a + 3);
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}