#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n, m, c, k;
int cnt = 0;
bitset<qwe> lne;
int a[qwe], p[qwe], q[qwe],plan[qwe];
bool vis[qwe];
int main()
{
    scanf("%d%d%d%d", &n, &m, &c, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        cnt |= a[i];
    }
    for (int i = 1; i <= m;i++){
        scanf("%d%d", &p[i],&q[i]);
        plan[p[i]] = 1;
    }
    for (int i = 0; i < k;i++){
        lne[i] = cnt % 2;
        cnt >>= 1;
        if(plan[i]&&lne[i]){
            vis[plan[i]] = 1;
            
        }
    }
}