#include<bits/stdc++.h>
using namespace std;
int a[2][1005],n, T;
int main(){
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
        {
            scanf("%d%d", &a[0][j], &a[1][j]);
        }
    }
    
    return 0;
}