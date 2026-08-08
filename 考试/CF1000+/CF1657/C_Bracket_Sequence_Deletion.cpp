#include <bits/stdc++.h>
#define ll long long
#define un unsigned
using namespace std;
const int qwe = 1e6 + 5;
int T;
int n, m;
int a[qwe];
char c[qwe];

int main()
{
    // freopen("/home/bai/code/test.in","r",stdin);
    // freopen("/home/bai/code/test.out","w",stdout);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        scanf("%s", c + 1);
        int f = 0, cnt = 0, ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (f == 0)
            {
                if (i != n)
                {
                    if (c[i] == '(' || (c[i] == ')' && c[i + 1] == ')'))
                    {
                        cnt++;
                        ans = i + 1;
                        i++;
                    }
                    else if (c[i] == ')' && c[i + 1] == '(')
                    {
                        f = 1;
                        i++;
                    }
                }
            }
            else if (c[i] == ')')
            {
                f = 0;
                cnt++;
                ans = i;
            }
        }
        printf("%d %d\n", cnt, n - ans);
    }
    return 0;
}