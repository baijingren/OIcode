#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int qwe = 10005;
ll len[qwe][3];
int n;
int lne(double xa, double ya, double xb, double yb)
{
    double xl = fabs(xa - xb), yl = fabs(ya - yb);
    double ans = xl * xl + yl * yl;
    return ans;
}
// struct Node
// {
//     int x, y;
// };
int main()
{
    freopen("/home/bai/code/test.in", "r", stdin);
    freopen("/home/bai/code/test.out", "w", stdout);
    int xa, xb, ya, yb;
    scanf("%d%d%d%d", &xa, &xb, &ya, &yb);
    // Node l, r;
    // if(xa < ya)
    // {
    //     l.x = xa, l.y = xb;
    //     r.x = ya, r.y = yb;
    // }
    // else
    // {
    //     l.x = ya, l.y = yb;
    //     r.x = xa, r.y = xb;
    // }
    // int mx = INT_MIN;
    scanf("%d", &n);
    int x, y;
    ll a = 0, b = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &x, &y);
        len[i][1] = lne(x, y, xa, xb);
        len[i][2] = lne(x, y, ya, yb);
        if(len[i][1] <= len[i][2])
        {
            a = max(a, len[i][1]);
        }
        else
        {
            b = max(b, len[i][2]);
        }
    }
    printf("%lld", a + b);
    return 0;
}
