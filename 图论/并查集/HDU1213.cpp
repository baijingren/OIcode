#include <bits/stdc++.h>
using namespace std;

const int qwe = 1e6 + 5;
int T, x, y, n, m;
int fa[qwe];

void init()
{
    for (int i = 1; i <= n; i++)
    {  
        fa[i] = i;
    }
}
int fnd(int x){
    if(fa[x] == x){
        return x;
    }
    else{
        return fnd(fa[x]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    while (T--)
    {
        init();
        cin >> n >> m;
        for (int i = 1; i <= m; i++)
        {
            cin >> x >> y;
            fa[x] = fnd(y);
        }
        for(int i=1;i<=n;i++){
            int tmp = fnd(i);
        }
    }
}