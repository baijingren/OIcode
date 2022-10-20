#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define X first
#define Y second
#define MP make_pair
const int qwe = 1e3 + 5;
int T, n, m, a, b, cnt = 0, cnttt = 0, ans=0;
PII Cu[qwe * qwe];
int De[qwe][qwe];
bool vis[qwe][qwe];
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d%d", &n, &m, &a, &b);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                scanf("%d", &De[i][j]);
                if(De[i][j]){
                    ans++;
                }
            }
        }
        for (int i = 1; i <= a; i++)
        {
            for (int j = 1; j <= b; j++)
            {
                int k;
                scanf("%d", &k);
                if (k)
                {
                    Cu[++cnt] = MP(i, j);
                }
            }
        }
        for (int i = 1; i <= n - a + 1; i++)
        {
            for (int j = 1; i <= m - b + 1; j++)
            {
                int cntt = 0, t = 0;
                for (int k = 1; k <= cnt; k++)
                {
                    if (De[i + Cu[k].X - 1][j + Cu[k].Y - 1] && !vis[i + Cu[k].X - 1][j + Cu[k].Y - 1])
                    {
                        vis[i + Cu[k].X - 1][j + Cu[k].Y - 1] = 1;
                        cnttt++;
                        cntt++;
                    }
                    else if (vis[i + Cu[k].X - 1][j + Cu[k].Y - 1])
                    {
                        t = 1;
                        for (int l = k; l >= 1; l--)
                        {
                            vis[i + Cu[l].X - 1][j + Cu[l].Y - 1] = 0;
                            cnttt--;
                        }
                        break;
                    }
                }
                if (cntt < cnt && t == 0)
                {
                    for (int k = 1; k <= cnt; k++)
                    {
                        if (De[i + Cu[k].X - 1][j + Cu[k].Y - 1])
                        {
                            vis[i + Cu[k].X - 1][j + Cu[k].Y - 1] = 0;
                            cnttt--;
                        }
                    }
                }
            }
        }
        if(cnttt==ans){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
}
// #include<bits/stdc++.h>
// using namespace std;
// const int qwe=1e3+5;
// int T,n,m,a,b;
// int Cu[qwe][qwe],De[qwe][qwe];
// int main(){
//     srand(time(NULL));
//     scanf("%d",&T);
//     while(T--){
//         scanf("%d%d%d%d",&n,&m,&a,&b);
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=n;j++){
//                 scanf("%d",&De[i][j]);
//             }
//         }
//         for(int i=1;i<=a;i++){
//             for(int j=1;j<=b;j++){
//                 scanf("%d",&Cu[i][j]);
//             }
//         }
//         printf("%s\n",random()%2?"YES":"NO");
//     }
// }