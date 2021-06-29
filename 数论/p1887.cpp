#include<bits/stdc++.h>
using namespace std;
int n, m;
int main()
{
    scanf("%d%d", &n, &m);
    int sa = n / m;
    int sb = n - sa * m;
    // cout<<sa<<' '<<sb;
    int ans;
    if (sb == 0)
    {
        // cout<<2;
        // cout<<sa<<' '<<m<<' '<<endl;
        // ans = pow(sa, m);
        // printf("%d", ans);
        for(int i = 1; i <= m; i++)
        {
            printf("%d ", sa);
        }
        return 0;
    }
    // cout<<3;
    // ans = pow(sa, (m - sb)) * pow(sa + 1, sb);
    // printf("%d", ans);
    for(int i = 1; i <= m - sb; i++)
    {
        printf("%d ", sa);
    }
    for(int i = 1; i <= sb; i++)
    {
        printf("%d ", sa + 1);
    }
    return 0;
}