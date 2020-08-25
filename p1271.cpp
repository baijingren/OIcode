#include<bits/stdc++.h>
using namespace std;
int n, m, a[2000005];
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a, a + m);
    for (int i = 0; i < m; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}