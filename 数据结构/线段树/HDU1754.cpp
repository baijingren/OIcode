#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
const int qwe = 1e6 + 5;
int T;
int n, m;
int a[qwe];
struct Segment_Tree
{
    int t[qwe];
    void pushup(int rt)
    {
        t[rt] = max(t[rt << 1 | 1], t[rt << 1]);
    }
    void build(int rt, int l, int r)
    {
        if (l == r)
        {
            t[rt] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(rt << 1, l, mid);
        build(rt << 1 | 1, mid + 1, r);
        pushup(rt);
    }
    void change(int rt, int l, int r, int x, int w)
    {
        if (l == r)
        {
            t[rt] = w;
            return;
        }
        int mid = (l + r) >> 1;
        if (mid < x)
        {
            change(rt << 1 | 1, mid + 1, r, x, w);
        }
        else
        {
            change(rt << 1, l, mid, x, w);
        }
        pushup(rt);
    }
    int query(int rt, int l, int r, int L, int R)
    {
        if (L <= l && R >= r)
        {
            return t[rt];
        }
        int mid = (l + r) >> 1;
        int ans = 0;
        if (L <= mid)
        {
            ans = max(ans, query(rt << 1, l, mid, L, R));
        }
        if (R > mid)
        {
            ans = max(ans, query(rt << 1 | 1, mid + 1, r, L, R));
        }
        return ans;
    }
} t;
int main()
{
    // freopen("/home/bai/code/test.in", "r", stdin);
    // freopen("/home/bai/code/test.out", "w", stdout);
    while (scanf("%d %d\n", &n, &m) != EOF)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d ", &a[i]);
        }
        t.build(1, 1, n);
        char c;
        int x, y;
        for (int i = 1; i <= m; i++)
        {
            scanf("%c %d %d ", &c, &x, &y);
            // cerr << c << ' ' << x << ' ' << y << endl;
            if (c == 'Q')
            {
                printf("%d\n", t.query(1, 1, n, x, y));
            }
            else if (c == 'U')
            {
                t.change(1, 1, n, x, y);
            }
        }
    }
    return 0;
}