#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6 + 5;
int n, cnt = 0;
int a[qwe], son[qwe], prt[qwe], p[qwe];
int nxt[qwe], pre[qwe];
// struct Node
// {
//     int pre, w, nxt;
// } hd[qwe];
int main()
{
    scanf("%d", &n);
    a[0] = a[n + 1] = -1;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        pre[i] = i - 1;
        nxt[i] = i + 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == a[i - 1])
        {
            son[i - 1] = i;
        }
        else
        {
            prt[++cnt] = i;
        }
    }
    int tot = 1;
    while (tot)
    {
        tot = 0;
        for (int i = 1; i <= cnt; i++)
        {
            if (prt[i] == 0)
                continue;
            p[++tot] = prt[i];
            nxt[pre[prt[i]]] = nxt[prt[i]];
            pre[nxt[prt[i]]] = pre[prt[i]];
            if (son[prt[i]] != 0)
            {
                prt[i] = son[prt[i]];
            }
            else
            {
                prt[i] = 0;
            }
        }
        for (int i = 1;i<=cnt;i++){
            if(prt[i]==0){
                swap(prt[i],prt[cnt]);
                cnt--;
            }
        }
        for (int i = 1; i <= cnt;i++){
            if(prt[i]==0){
                continue;
            }
            if(a[pre[prt[i]]]==a[prt[i]]){
                son[pre[prt[i]]] = prt[i];
                prt[i] = 0;
            }
        }
        if(tot==0){
            break;
        }
        sort(p+1,p+tot+1);
        for (int i = 1; i <= tot;i++){
            printf("%d ", p[i]);
        }
        printf("\n");
    }
    return 0;
}