#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e3 + 5;
int h, w, d, ans = 0;
int s[qwe][qwe];
vector<pair<int, int>> t;
int mp[2][4]{
    {1, -1, 0, 0},
    {0, 0, 1, -1}};
queue<pair<int, int>> q;
int main()
{
    cin >> h >> w >> d;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            char c;
            cin >> c;
            if (c == '#')
            {
                s[i][j] = -1;
            }
            else if (c == '.')
            {
                s[i][j] = 0x3f3f3f3f;
            }
            else if (c == 'H')
            {
                s[i][j] = 0;
                t.push_back(make_pair(i, j));
                // cerr << i << ' ' << j << endl;
            }
        }
    }

    while (q.size())
    {
        q.pop();
    }
    for (auto st : t)
    {
        q.push(st);
    }
    while (q.size())
    {
        auto U = q.front();
        q.pop();
        int ux = U.first, uy = U.second;
        for (int i = 0; i < 4; i++)
        {
            int vx = ux + mp[0][i], vy = uy + mp[1][i];
            if (s[vx][vy] == -1)
            {
                continue;
            }
            if (s[vx][vy] <= s[ux][uy] + 1)
            {
                continue;
            }
            s[vx][vy] = s[ux][uy] + 1;
            q.push(make_pair(vx, vy));
        }
    }
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            // cerr << s[i][j] << ' ' ;
            if(s[i][j] <= d && s[i][j] != -1){
                ans ++;
            }
        }
        // cerr << endl;
    }
    cout << ans;
    return 0;
}