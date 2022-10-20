#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6 + 5;
int n, mx, m2x, sum = 0, cnt, ans;
int a[qwe], nxt[qwe];
bool cmp(int x, int y)
{
    return x > y;
}
void dfs(int x, int y, int z)//长度，
{
    if (x > n)
    {
        ans = min(ans, k);
        return;
    }
    dfs(x + 1, )
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
        // mx = a[i] > mx ? a[i],m2x=a[i] : mx;
        mx = max(mx, a[i]);
    }
    sort(a + 1, a + n + 1, cmp);
    nxt[n] = n;
    for (int i = n - 1; i >= 1; i--)
    {
        if (a[i] == a[i + 1])
        {
            nxt[i] = nxt[i + 1];
        }
        else
        {
            nxt[i] = i;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        dfs(i, 0);
    }
}