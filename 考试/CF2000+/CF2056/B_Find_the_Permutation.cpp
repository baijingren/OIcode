#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e3 + 5;
int T, n, m;
int a[qwe][qwe];
int out[qwe];

struct Edge{
    int nxt, to;
} edge[qwe];
int cnt = 0, hd[qwe];
void add(int u, int v){
    edge[++cnt].nxt = hd[u];
    edge[cnt].to = v;
    hd[u] = cnt;
}
bool vis[qwe];
vector<int> ans;
void dfs(int u){
    ans.push_back(u);
    for(int i = n; i >= u; i--){
        if(a[u][i] == 1){
            int v = i;
            out[v]--;
            if(out[v] == 0){
                dfs(v);
            }
        }
    }
}
string s;
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        cnt = 0;
        memset(hd, 0, sizeof(hd));
        memset(out, 0, sizeof(out));
        memset(vis, 0, sizeof(vis));
        while(ans.size()){
            ans.pop_back();
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                char c;
                cin >> c;
                if (c == '0')
                {
                    a[i][j] = 0;
                }
                else if(c == '1'){
                    a[i][j] = 1;
                    if(i < j){
                        out[j]++;
                        // cerr << j << ' ' << i << endl;
                    }
                }
            }
        }
        for(int i = n; i >= 1; i--){
            if(vis[i]){
                continue;
            }
            if(out[i] == 0){
                dfs(i);
            }
        }
        for(int u:ans){
            cout << u << ' ';
        }
        cout << endl;

    }
    return 0;
}