#include<bits/stdc++.h>
using namespace std;
const int qwe=2e3+5;
const int M=1e7+5;
int n,m,tot;
vector<int> e[M];
string a[qwe];
int pos[qwe][qwe];
int id[qwe][qwe];
int mp[2][4]={
    {0,-1,0,1},
    {1,0,-1,0}
};
void fill(int ux, int uy, int w) {
    tot++;
    id[ux][uy] = w;
    if (a[ux][uy] == '-' || a[ux][uy] == '|')
        return;
    for (int i = 0; i < 4; i++) {
        int vx = ux + mp[0][i], vy = uy + mp[1][i];
        if (!id[vx][vy] && a[vx][vy])
            fill(vx, vy, w);
    }
    return;
}
int findid(int x, int y) {
    while (id[x][y] <= 0) {
        id[x][y] = -1;
        for (int i = 0; i < 4; i++) {
            int vx = x + mp[0][i], vy = y + mp[1][i];
            if (a[vx][vy] && a[vx][vy] != '.' && ~id[vx][vy]) {
                x = vx, y = vy;
                break;
            }
        }
    }
    return id[x][y];
}
void dfs(int u){
    // for(auto v:e[u]){
    for(int i=e[u].size()-1;i>=0;i--){
        int v=e[u][i];
        dfs(v);
    }
    for(int i=pos[1][u];isdigit(a[pos[0][u]][i]);i++){
         putchar(a[pos[0][u]][i]);
    }
    putchar('\n');
    return;
}
int st,num;
int main(){
    freopen("T1.in","r",stdin);
    freopen("T1.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            if (isdigit(a[i][j]) && !id[i][j]) {
                fill(i, j, ++num);
                pos[0][num] = i, pos[1][num] = j;
                if (a[i][j] == '1' && !isdigit(a[i][j + 1]))
                    st = num;
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (id[i][j] > 0) {
                if (!id[i][j - 1] && a[i][j - 1] == '-') {
                    int t = id[i][j];
                    id[i][j] = -1;
                    e[t].push_back(findid(i,j-1));
                } else if (!id[i][j + 1] && a[i][j + 1] == '-') {
                    int t = id[i][j];
                    id[i][j] = -1;
                    e[t].push_back(findid(i,j+1));
                }
            }
        }
    }
    // cerr<<st<<endl;
    dfs(st);
    return 0;
}