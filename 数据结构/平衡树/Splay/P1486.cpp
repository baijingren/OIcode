#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6 + 5;
int n, m, delta;
class Splay
{
private:
    int tot = 0;
    struct Tree
    {
        int p, ch[2], val, size;
        int cnt = 1;
    };

public:
    int root = 0;
    Tree t[qwe];
    void pushup(int x)
    {
        t[x].size = t[t[x].ch[0]].size + t[t[x].ch[1]].size + t[x].cnt;
    }
    void splay(int x, int fa)
    {
        while (t[x].p != fa)
        {
            cout<<1;
            int y = t[x].p, z = t[y].p;
            if (z != fa)
            {
                (t[z].ch[0] == y) ^ (t[y].ch[0] == x) ? rotate(x) : rotate(y);
            }
            rotate(x);
        }
        if (!fa)
            root = x;
    }
    void rotate(int x)
    {
        int y = t[x].p, z = t[y].p;
        int k = (x == t[y].ch[1]);
        t[z].ch[t[z].ch[1] == y] = x;
        t[x].p = z;
        t[y].ch[k] = t[x].ch[k ^ 1];
        t[t[x].ch[k ^ 1]].p = y;
        t[x].ch[k ^ 1] = y;
        t[y].p = x;
        pushup(y), pushup(x);
        // pushdown(y),pushdown(x);
    }
    int insert(int x)
    {
        int u = root, fa = 0;
        while (u)
        {
            fa = u;
            u = t[u].ch[x > t[u].val];
        }
        if (u)
        {
            t[u].cnt++;
        }
        else
        {
            u = ++tot;
            if (fa)
            {
                t[fa].ch[t[fa].val < x] = u;
            }
            t[u].p = fa;
            t[u].val = x;
            t[u].cnt = 1;
            t[u].size = 1;
        }
        splay(u, 0);
        return u;
    }
    void find(int x)
    {
        int u = root;
        if (!u)
            return;
        while (t[u].ch[t[u].val < x] && x != t[u].val)
        {
            u = t[u].ch[t[u].val < x];
        }
        splay(u, 0);
    }
    int nxt(int x, int f)
    {
        find(x);
        int u = root;
        if (t[u].val > x && f)
        {
            return u;
        }
        if (t[u].val < x && !f)
        {
            return u;
        }
        u = t[u].ch[f];
        while (t[u].ch[f ^ 1])
            // cout<<1;
            u = t[u].ch[f ^ 1];
        return u;
    }
    void del(int x)
    {
        int fr = nxt(x, 0), bh = nxt(x, 1);
        splay(fr, 0);
        splay(bh, fr);
        int d = t[bh].ch[0];
        if (t[d].cnt > 1)
        {
            t[d].cnt--;
            splay(d, 0);
        }
        else
        {
            t[bh].ch[0] = 0;
        }
    }
    int kth(int x)
    {
        int u = root;
        while (t[u].size < x)
        {
            // cout<<1;
            return 0;
        }
        while (1)
        {
            int y = t[u].ch[0];
            if (x > t[y].size + t[u].cnt)
            {
                x -= (t[y].size + t[u].cnt);
                u = t[u].ch[1];
            }
            else if (t[y].size >= x)
            {
                u = y;
            }
            else
            {
                return t[u].val;
            }
        }
    }
};
Splay s;
int main()
{
    scanf("%d%d", &n, &m);
    int l = s.insert(1e9);
    int r = s.insert(-1e9);
    for (int i = 1; i <= n; i++)
    {
        int x;
        char c;
        scanf(" %c %d", &c, &x);
        // printf("%d ",c);
        switch (c)
        {
        case 'I':
            if (x < m)
            {
                continue;
            }
            s.insert(x);
            break;
        case 'A':
            delta += x;
            break;
        case 'S':
            delta -= x;
            r = s.kth(m - delta);
            s.splay(r, 0), s.splay(l, r);
            s.t[r].ch[1] = 0;
            s.pushup(l), s.pushup(r);
            break;
        case 'F':
            if (s.t[s.root].size < 2 + x)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", s.kth(s.t[s.root].size) + delta);
            }
            break;
        }
    }
}