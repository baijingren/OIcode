#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6 + 5;
int T, n, l,r,ml,mr;
int a[qwe],vis[qwe],fa[qwe],pa[qwe];
void clear(){
    l = 1, r = n;
    ml = n, mr = n - 1;
    memset(vis, 0, sizeof(vis));
    memset(fa, 0, sizeof(fa));
}
int main()
{
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        clear();
        for (int i = 1; i <= n*2; i++)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= n*2;i++){
            if(vis[a[i]]){
                fa[vis[a[i]]] = i;
                pa[i] = vis[a[i]];
            }
            else{
                vis[a[i]] = i;
            }
        }
        int pos = -1;
        l = 1, r = n * 2, ml = pa[1] - 1, mr = pa[1] + 1;
        for (int i = 2; i <= n; i++)
        {
            if(pa[l]==ml&&ml>=i){
                l++;
                ml--;
                pos = 1;
            }
            else if(pa[l]==mr&&mr>=i){
                l++;
                mr++;
                pos = 1;
            }
            else if(pa[r]==ml&&r>=ml){
                r--;
                ml--;
                pos = 0;
            }
            else if(pa[r]==mr&&r>=mr){
                r--;
                mr++;
                pos = 0;
            }
            if(pos==1){
                printf("L");
                pos = -1;
            }
            else if(pos==2){
                printf("R");
                pos = -1;
            }
            else if(pos==-1){
                printf("-1");
                break;
            }
        }
        for(int i=1;i<=n;i++){
            
        }
    }
    return 0;
}