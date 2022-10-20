#include <bits/stdc++.h>
using namespace std;
const int qwe = 1000005;
int n, m;
int f[qwe][55], k[qwe][55];
struct yea {
    int y, mm;
} a[qwe];
int chk(int x) {
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (a[mid].y < x)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a[i].y, &a[i].mm);
        // if (a[i].y - a[i - 1].y > 1 && i != 1) {
            //			for(int j=a[i-1].y+1;j<a[i].y;j++)
            //			{
            // k[i][0] = -1;
            //				a[i+1]=a[i];
            //				a[i]={j,0};
            //				i++;
            //				n++;
            //			}
            //			k[i][i-1]=-1;
        // }
        f[i][0] = a[i].mm;
    }
    //	for(int i=1;i<=n;i++){
    //		if(k[i][0]==-1) cout<<i<<' ';
    //	}
    int t = log2(n);
    for (int j = 1; j <= t + 1; j++) {
        for (int i = 1; i <= n - (1 << j) + 1; i++) {
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            // k[i][j] = min(k[i][j - 1], k[i + (1 << (j - 1))][j - 1]);
        }
    }
    //	for(
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        int id = u;
        if (v > a[n].y) {
            printf("maybe\n");
            continue;
        }
        if (u < a[1].y) {
            printf("maybe\n");
            continue;
        }
        if (u > v) {
            printf("false\n");
            continue;
        }
        // u = chk(u + 1);
        // v = chk(v - 1);
        // id = chk(id);
        int kk = log2(v - u + 1);
        int c = max(f[u][kk], f[v - (1 << kk) + 1][kk]);
        // if()
        // if (a[id].mm >= c) {
        //     if (min(k[u][kk], k[v - (1 << kk) + 1][kk]) == -1) {
        //         printf("maybe\n");
        //     } else {
        //         printf("true\n");
        //     }
        // } else {
        //     printf("false\n");
        // }
    }
    return 0;
}
