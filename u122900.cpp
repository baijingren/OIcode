#include <bits/stdc++.h>
using namespace std;
const int qwe = 300005;
int n, fmx, mx;
int a[qwe], f[qwe],s[qwe];
struct SAVE
{
    int bg, ed, ln;
} sv;
bool cmp(int x, int y)
{
    return x > y;
}
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    clock_t  st ,ed;
    st = clock();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        s[i] = s[i - 1] + a[i];
        mx = max(mx, a[i]);
        for (int j = i; j > 1; j--) //长度为i的最大字段和
        {
            f[i * n + j] = s[i] - s[i - j];
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= i; j++) //长度为i的最大字段和
    //     {
    //         f[i] = max(s[j] - s[j - i], f[i]);
    //         // if (f[j] >= fmx)
    //         // {
    //         //     if(sv.ed < i - j || sv.bg > i)
    //         //     {
    //         //         smx = fmx;
    //         //     }
    //         //     fmx = f[j];
    //         //     sv.bg = i - j + 1;
    //         //     sv.ed = i;
    //         // }
    //         // if (f[j] < fmx && (sv.ed < i - j || sv.bg > i))
    //         // {
    //         //     smx = max(smx, f[j]);
    //         // }
    //     }
    // }
    f[n * n] = mx;
    sort(f + 1, f + n * n + 1, cmp);
    printf("%d\n", f[1] + f[2]);
    ed = clock();
    printf("%ldus", (ed - st));
    return 0;
}