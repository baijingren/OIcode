#include <bits/stdc++.h>
using namespace std;
const int qwe = 100005;
int n;
// char sa[qwe], sb[qwe];
int sa[qwe], sb[qwe], mp[qwe];
// int f[qwe][qwe];
int f[qwe];
int main()
{
    scanf("%d ", &n);
    // scanf("%s", sa);
    // scanf("%s", sb);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &sa[i]);
        mp[sa[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &sb[i]);
    }
    int len = 0;
    f[0] = sb[0];
    for (int i = 1; i <= n; i++)
    {
        if (f[len] < mp[sb[i]])
        {
            f[++len] = mp[sb[i]];
        }
        else
        {
            int l = 0, r = len;
            while (l < r)
            {
                int mid = (l + r) / 2;
                if (f[mid] <= mp[sb[i]])
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid;
                }
            }
            // f[l] = mp[sb[i]];
            f[l] = min(mp[sb[i]], f[l]);
        }
    }
    // printf("%d", f[n][n]);
    printf("%d", len);
    return 0;
}