#include <bits/stdc++.h>
using namespace std;
const int qwe = 1005;
int n;
int a[qwe],q[qwe];
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    int tl = 1, l = 1;
    q[tl] = a[1];
    for (int i = 1; i <= n; i++)
    {
        if (l != 0&&a[i] < q[tl])
        {
            tl++;
            l--;
            q[tl] = a[i];
        }
        else
        {
            while (a[i] >= q[tl]&&q[tl])
            {
                q[tl] = 0;
                tl--;
                l--;
            }
        }
        
    }
    return 0;
}