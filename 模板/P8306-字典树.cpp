#include <bits/stdc++.h>
using namespace std;
const int qwe = 3e6 + 5;
unsigned int c(char a)
{
    if (a >= 'A' && a <= 'Z')
    {
        return a - 'A';
    }
    else if (a >= 'a' && a <= 'z')
    {
        return a - 'a' + 26;
    }
    else if (a >= '0' && a <= '9')
    {
        return a - '0' + 52;
    }
}
struct Trie
{
    int f[qwe][62];
    int cnt = 0;
    int v[qwe];
    void init()
    {
        for(int i=0;i<=cnt;i++){
            v[i]=0;
            for(int j=0;j<=62;j++){
                f[i][j]=0;
            }
        }
        cnt = 0;
    }
    void add(string s)
    {
        int u = 0;
        int len = s.length();
        for (int i = 0; i < len; i++)
        {
            if (f[u][c(s[i])])
            {
                u = f[u][c(s[i])];
            }
            else
            {
                f[u][c(s[i])] = ++cnt;
                u = cnt;
            }
            v[u]++;
        }
        // v[u]++;
    }
    int query(string s)
    {
        int u = 0;
        int len = s.length();
        for (int i = 0; i < len; i++)
        {
            if (f[u][c(s[i])])
            {
                u = f[u][c(s[i])];
            }
            else
            {
                return 0;
            }
        }
        return v[u];
    }
} t;
int n, q, T;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    while (T--)
    {
        cin >> n >> q;
        t.init();
        for (int i = 1; i <= n; i++)
        {
            cin >> s;
            t.add(s);
        }
        for (int i = 1; i <= q; i++)
        {
            cin >> s;
            cout << t.query(s) << '\n';
        }
    }
    return 0;
}