//
// Created by Bai Jingren on 2021/10/6.
//
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int qwe = 1e6 + 5;
int n;
ll ans;
ll a[qwe], s[qwe];
struct Node
{
    int num, size;
} sum[qwe];
// ll C(int x)
// {
//     c[1][0] = 1;
//     c[1][1] = 1;
//     for (int i = 2; i <= x; i++)
//     {
//         for (int j = 0; j <= 4; j++)
//             c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
//     }
// }
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        // sum[a[i]]++;
    }
    sort(a + 1, a + n + 1);
    int now, cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == now)
        {
            sum[cnt].size++;
        }
        else
        {
            s[cnt]=s[cnt-1]+sum[cnt].size;
            cnt++;
            now = a[i];
            sum[cnt].num = a[i];
            sum[cnt].size++;
        }
    }
    // C(n*3);
    for (int i = cnt; i >= 1; i--)
    {
        // for (int j = i; j >= 1; j--)
        // {
        //     // cout << endl;
        //     // cout << i << ' ' << j << ' ' << sum[i].num << ' ' << sum[j].num << endl;
        //     if (sum[j].num < (int)sum[i].num * 0.9)
        //     {
        //         // cout << "aaa" << endl;
        //         break;
        //     }
        //     if(i==j){
        //         // ans += c[sum[i].size][2];
        //         int s = sum[i].size;
        //         ans += (s * (s - 1) / 2);
        //         continue;
        //     }
        //     ans += (sum[i].size * sum[j].size);
        //     // cout << sum[i].size << ' ' << sum[j].size << endl;
        //     // ans += c[sum[i].size + sum[j].size][2];
        // }
    //    int l=0,r=i;
    //    while(l<r){
    //        int mid=(l+r)/2;
    //        if(sum[mid].num<int(sum[i].num*0.9)) l=mid+1;
    //        else r=mid;
    //        ans+=(s[i]-s[l-1]-sum[i].size)*sum[i].size;
    //        ans+=(sum[i].size*(sum[i].size-1)/2);
    //    }
    }
    printf("%d", ans);
    return 0;
}
