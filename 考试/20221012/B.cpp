#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define he(x) this->x
namespace INPUT_SPACE
{
    const int S = (1 << 20) + 5;
    char B[S], *H, *T;
    inline int gc()
    {
        if (H == T)
            T = (H = B) + fread(B, 1, S, stdin);
        return (H == T) ? EOF : *H++;
    }
    inline unsigned int inn()
    {
        unsigned int x, ch;
        while ((ch = gc()) < '0' || ch > '9')
            ;
        x = ch ^ '0';
        while ((ch = gc()) >= '0' && ch <= '9')
            x = x * 10 + (ch ^ '0');
        return x;
    }
}
using INPUT_SPACE::inn;
const int qwe = 1e6 + 5;
int T, n;
struct Node
{
    int a, b, c, d;
    Node() {}
    Node(int a, int b, int c, int d)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }
    Node operator*(const Node &a) const
    {
        Node A, B, ans;
        B = a;
        A = {he(a), b, c, d};
        if (!B.a)
        {
            return A;
        }
        if (!he(a))
        {
            return B;
        }
        if (B.a == B.c)
        {
            return B;
        }
        if (he(a) == he(c))
        {
            return A;
        }
        if (A.a > B.a)
        {
            swap(A, B);
        }
        if (A.c <= B.a)
        {
            return Node(1, 0, 1, 0);
        }
        ans.a = B.a;
        ans.c = min(A.c, B.c);
        if (A.b > B.b)
        {
            swap(A, B);
        }
        if (A.d <= B.b)
        {
            return Node(1, 0, 1, 0);
        }
        ans.b = B.b;
        ans.d = min(A.d, B.d);
        return ans;
    }
};
Node a[qwe], p[qwe];
int main()
{
    freopen("T2.in","r",stdin);
    freopen("T2.out","w",stdout);
    T = inn();
    while (T--)
    {
        n = inn();
        for (int i = 1; i <= n; i++)
        {
            a[i].a = inn()+1;
            a[i].b = inn()+1;
            a[i].c = inn()+1;
            a[i].d = inn()+1;
        }
        for (int i = 1; i < n; i++)
        {
            p[i] = p[i - 1] * a[i];
        }
        ll ans = 0;
        Node t, tmp;
        tmp = {0, 0, 0, 0};
        // for(int i=1;i<=n;i++){
        //     cerr<<p[i].a<<' '<<p[i].b<<' '<<p[i].c<<' '<<p[i].d<<endl;
        // }
        for (int i = n; i >= 1; i--)
        {
            t = p[i - 1] * tmp;
            // cerr<<"T:"<<t.a<<' '<<t.b<<' '<<t.c<<' '<<t.d<<endl;
            ans += (ll)(t.c - t.a) * (t.d - t.b);
            tmp = tmp * a[i];
            // cerr<<ans<<endl;
        }
        // cerr<<tmp.a<<' '<<tmp.b<<' ' <<tmp.c<<' '<<tmp.d<<endl;
        cout << ans - (long long)(tmp.c - tmp.a) * (tmp.d - tmp.b) * (n - 1) << '\n';
    }
}
