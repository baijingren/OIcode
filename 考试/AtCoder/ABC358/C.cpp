#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6 + 5;
int n, m;
unsigned int s[qwe];
int sum, ans = INT_MAX;
bool vis[qwe];
void dfs(int u, int cnt, int dep)
{
    if (((s[u] & cnt) ^ cnt) == 0)
    {
        ans = min(ans, dep);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            dfs(i, ((s[i] & cnt) ^ cnt), dep + 1);
            vis[i] = 0;
        }
    }
}
int main()
{
    cin >> n >> m;
    sum = (1 << m) - 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char c;
            cin >> c;
            if (c == 'x')
            {
                continue;
            }
            else if (c == 'o')
            {
                s[i] += 1 << (j - 1);
            }
            else
            {
                cin >> c;
            }
        }
        // cout << (s[i] | s[i-1]) << endl;
    }
    dfs(1, sum, 0);
    if(ans == 0){
        cout<<1<<endl;
        return  0;
    }
    cout << ans << endl;
    return 0;
}