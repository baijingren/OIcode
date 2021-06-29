#include<bits/stdc++.h>
using namespace std;
int T;
map<int, map<int, int>> mp;
int chk(int x, int y)
{
    cout << x << ' ' << y << endl;
    if (mp[x][y])
    {
        return mp[x][y];
    }
    int ans = 0;
    for (int i = 1; i <= y; i++)
    {
        ans = ans * 10 + x;
    }
    return ans;
}
void dfs(int x, int y, int n)
{
    if(x > n)
    {
        return;
    }
    if(x == n)
    {
        printf("%d", y);
        return;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; chk(j, i) <= 10000; j++)
        {
            dfs(chk(j, i), y + 1, n);
        }
    }
}
int main()
{
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        dfs(1, 0, n);
    }
    return 0;
}