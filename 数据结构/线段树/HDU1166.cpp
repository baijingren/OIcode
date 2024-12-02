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
        t[rt] = t[rt << 1 | 1] + t[rt << 1];
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
            t[rt] += w;
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
            ans += query(rt << 1, l, mid, L, R);
        }
        if (R > mid)
        {
            ans += query(rt << 1 | 1, mid + 1, r, L, R);
        }
        return ans;
    }
} t;
int main()
{
    // freopen("/home/bai/code/test.in", "r", stdin);
    // freopen("/home/bai/code/test.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    for (int count = 1; count <= T; count++)
    {
        printf("Case %d:\n", count);
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        t.build(1, 1, n);
        string a;
        int x, y;
        while (1)
        {
            cin >> a;
            // cerr << a << endl;
            if (a.compare("End") == 0)
            {
                break;
            }
            else if (a.compare("Add") == 0)
            {
                cin >> x >> y;
                t.change(1, 1, n, x, y);
            }
            else if (a.compare("Sub") == 0)
            {
                cin >> x >> y;
                t.change(1, 1, n, x, -y);
            }
            else if (a.compare("Query") == 0)
            {
                cin >> x >> y;
                // cerr<<1<<' '<<x<<' '<<y<<endl;
                printf("%d\n", t.query(1, 1, n, x, y));
            }
        }
    }
    return 0;
}