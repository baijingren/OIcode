#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6 + 5;
int n, root = 0;
class Splay
{
private:
    // struct Splay
    int tot = 0;
    struct Tree
    {
        int pa, cnt, ch[2], size, val;
    };
    Tree t[qwe];

public:
    void update(int x)
    {
        t[x].size = t[t[x].ch[1]].size + t[t[x].ch[0]].size + t[x].cnt;
    }
    void rotate(int x)
    {
        int y = t[x].pa, z = t[y].pa;
        int k = (t[y].ch[1] == x);
        t[z].ch[t[z].ch[1] == y] = x;
        t[x].pa = z;
        t[y].ch[k] = t[x].ch[k ^ 1];
        t[t[x].ch[k ^ 1]].pa = y;
        t[x].ch[k ^ 1] = y;
        t[y].pa = x;
        update(y), update(x);
    }
    void splay(int x, int a)
    {
        while (t[x].pa != a)
        {
            int y = t[x].pa, z = t[y].pa;
            if (z != a)
            { //同侧：t[z].ch[0]==y -> 1 && t[y].ch[0]==x ->1 1^1==0;或 t[z].ch[0]!=y -> 0 && t[y].ch[0]!=x -> 0 0^0==0
                (t[z].ch[0] == y) ^ (t[y].ch[0] == x) ? rotate(y) : rotate(x);
            }
            rotate(x);
        }
        if (!a)
        {
            root = x;
        }
    }
    void insert(int x)
    {
        int u = root, fa = 0;
        while (u && t[u].val != x)
        {
            fa = u;
            u = t[u].ch[x > t[u].val];
            // cout << 1;
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
                t[fa].ch[x > t[fa].val] = u;
            }
            // t[u].ch[0] = t[u].ch[1] = 0;
            // t[u].pa = fa;
            // t[u].val = x;
            // t[u].cnt = 1;
            // t[u].size = 1;
            t[tot].pa = fa;
            t[tot].val = x;
            t[tot].cnt = 1;
            t[tot].size = 1;
        }
        splay(u, 0);
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
        if (t[u].size < x)
        {
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
    void out()
    {
        for (int i = 1; i <= n; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            switch (x)
            {
            case 1:
                insert(y);
                break;

            case 2:
                del(y);
                break;

            case 3:
                find(y);
                printf("%d\n", t[t[root].ch[0]].size);
                break;

            case 4:
                printf("%d\n", kth(y + 1));
                break;

            case 5:
                printf("%d\n", t[nxt(y, 0)].val);
                break;

            case 6:
                printf("%d\n", t[nxt(y, 1)].val);
                break;
            }
        }
    }
    //插入一段序列
    //删除一段序列
    
};
Splay s;
int main()
{
    scanf("%d", &n);
    s.insert(1e9);
    s.insert(-1e9);
    s.out();
    // insert(1e9);
    // insert(-1e9);
    // for(int i=1;i<=n;i++){
    //     scanf("")
    // }
    return 0;
}