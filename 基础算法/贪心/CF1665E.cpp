#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6 + 5;
int n, q;
int T;
int a[qwe];
class SegmentTree
{
public:
    struct Tree
    {
        int num, id;
        bool operator<(const Tree &a) const
        {
            return num < a.num;
        }
    } t[qwe];
    void pushup(int rt)
    {
        t[rt] = min(t[rt << 1], t[rt << 1 | 1]);
    }
    void build(int rt, int l, int r)
    {
        if (l == r)
        {
            t[rt].num = a[l];
            t[rt].id = l;
            return;
        }
        int mid = (l + r) >> 1;
        build(rt << 1, l, mid);
        build(rt << 1 | 1, mid + 1, r);
        pushup(rt);
    }
    Tree query(int rt, int l, int r, int L, int R)
    {
        if (L <= l && R >= r)
        {
            return t[rt];
        }
        Tree ans = {INT_MAX, INT_MAX};
        int mid = (l + r) >> 1;
        if (L <= mid)
        {
            ans = min(ans, query(rt << 1, l, mid, L, R));
        }
        if (R > mid)
        {
            ans = min(ans, query(rt << 1 | 1, mid + 1, r, L, R));
        }
        return ans;
    }
    void change(int rt, int l, int r, int x, int w)
    {
        if (l == r)
        {
            t[rt].id = x;
            t[rt].num = w;
            return;
        }
        int mid = (l + r) >> 1;
        if (x <= mid)
        {
            change(rt << 1, l, mid, x, w);
        }
        else
        {
            change(rt << 1 | 1, mid + 1, r, x, w);
        }
        pushup(rt);
    }
} t;
vector<SegmentTree::Tree> tmp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        // for (int i = 1; i <= n; i++)
        // {
        //     t.change(1, 1, n, i, a[i]);
        // }
        t.build(1, 1, n);
        cin >> q;
        for (int i = 1; i <= q; i++)
        {
            int l, r;
            cin >> l >> r;
            // cerr << "LR:" << l << ' ' << r << endl;
            tmp.clear();
            int lim = min(r - l + 1, 31);
            for (int i = 1; i <= lim; i++)
            {
                tmp.push_back(t.query(1, 1, n, l, r));
                t.change(1, 1, n, tmp.back().id, INT_MAX);
            }
            int mn = INT_MAX;
            // for (auto v : tmp)
            // {
            //     cerr << "DE:" << v.id << ' ' << v.num << endl;
            // }
            for (int i = 0; i < tmp.size(); i++)
            {
                for (int j = i + 1; j < tmp.size(); j++)
                {
                    mn = min(tmp[i].num | tmp[j].num, mn);
                }
            }
            cout << mn << '\n';
            for (SegmentTree::Tree v : tmp)
            {
                t.change(1, 1, n, v.id, a[v.id]);
            }
        }
    }
    return 0;
}