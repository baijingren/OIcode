#include<bits/stdc++.h>
using namespace std;
const int qwe = 5005;
int n, m;
int a[qwe][qwe], s[qwe][qwe];
int mv[2][5] = {
    {0, 0, 0, 1, -1},
    {0, 1, -1, 0, 0}};
int vis[qwe][qwe];
struct Node
{
    int x, y;
    bool wo;
};
queue<Node> q;
int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    memset(vis, -1, sizeof(vis));
    Node ss;
    ss.wo = 0, ss.x = 1, ss.y = 1;
    q.push(ss);
    ss.wo = 1, ss.x = n, ss.y = m;
    q.push(ss);
    vis[1][1] = 0;
    vis[n][m] = 1;
    s[1][1] = 1;
    s[n][m] = 1;
    while(!q.empty())
    {
        Node u;
        u = q.front();
        q.pop();
        // cout << u.x << ' ' << u.y << ' ' << u.wo << '1';
        for (int i = 1; i <= 4; i++)
        {
            Node v;
            v.x = u.x + mv[0][i], v.y = u.y + mv[1][i], v.wo = u.wo;
            // cout << v.x << ' ' << v.y << ' ' << v.wo << endl;
            if (v.x > 0 && v.y > 0 && v.x <= n && v.y <= m)
            {
                // cout << "qweqwe" << vis[v.x][v.y] << endl;
                if(vis[v.x][v.y] != -1 && vis[v.x][v.y] != u.wo)
                {
                    // cout << "rtyrty";
                    printf("%d", s[u.x][u.y] + s[v.x][v.y] - 1);
                    return 0;
                }
                if (a[v.x][v.y] == 0 && vis[v.x][v.y] == -1)
                {
                    q.push(v);
                    vis[v.x][v.y] = v.wo;
                    s[v.x][v.y] = s[u.x][u.y] + 1;
                }
                
            }
        }
    }
    printf("wo tai nan le");
    return 0;
}