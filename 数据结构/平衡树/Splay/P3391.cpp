#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6 + 5;
int n, m;
class Splay
{
private:
    int tot = 0;
    struct Tree
    {
        int p, ch[2], cnt, val, size, flag; //flag标记
    };

public:
    Tree t[qwe];
    int root = 0;
    void pushup(int x)
    {
        t[x].size = t[t[x].ch[0]].size + t[t[x].ch[1]].size + t[x].cnt;
    }
    void pushdown(int x)
    { //懒标记下传
        //root->left,root->right
        if (t[x].flag)
        {
            swap(t[x].ch[0], t[x].ch[1]);
            t[t[x].ch[0]].flag ^= 1;
            t[t[x].ch[1]].flag ^= 1;
            t[x].flag = 0;
        }
    }
    void splay(int x, int fa)
    {
        while (t[x].p != fa)
        {
            int y = t[x].p, z = t[y].p;
            if (z != fa)
            {
                (t[z].ch[0] == y) ^ (t[y].ch[0] == x) ? rotate(y) : rotate(x);
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
    void insert(int x)
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
        splay(u,0);
    }
    int kth(int x)
    {
        int u = root;
        while (1)
        {
            pushdown(u);
            // cout<<1;
            int y = t[u].ch[0];
            // if (x > t[y].size + t[u].cnt)
            // {
            //     x -= (t[y].size + t[u].cnt);
            //     u = t[u].ch[1];
            // }
            // else if (t[y].size >= x)
            // {
            //     u = y;
            // }
            // else
            // {
            //     return u;
            // }
            if(t[y].size>=x){
                u=y;
            }
            else if(t[y].size+1==x){
                return u;
            }
            else{
                x-=t[y].size+1;
                u=t[u].ch[1];
            }
        }
        return -1;
    }
    void out(int u)
    {
        pushdown(u);
        if (t[u].ch[0])
        {
            out(t[u].ch[0]);
        }
        if (t[u].val >= 1 && t[u].val <= n)
        {
            printf("%d ", t[u].val);
        }
        if (t[u].ch[1])
        {
            out(t[u].ch[1]);
        }
    }
};
Splay s;
int main()
{
    scanf("%d%d", &n, &m);
    // s.insert(1e9);
    // s.insert(-1e9);
    // s.out();
    for (int i = 0; i <= n+1; i++)
    {
        s.insert(i);
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        int l = s.kth(x), r = s.kth(y + 2);
        s.splay(l, 0), s.splay(r, l);
        s.t[s.t[r].ch[0]].flag ^= 1;
    }
    s.out(s.root);
    return 0;
}