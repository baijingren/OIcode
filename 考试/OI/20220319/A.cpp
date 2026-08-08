#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6 + 5;
int n, q;
long long ans = 0;
int a[qwe], b[qwe];
int k[qwe];
void mersort(int l, int r)
{
    // if(l==r){
    //     // k[l]=b[l];
    //     return;
    // }
    // // int mid=l+(r-l)/2;
    // int mid=(l+r)/2;
    // // cout<<mid;
    // mersort(l,mid);
    // mersort(mid+1,r);
    // int i,j,cnt=l;
    // for(i=l,j=mid+1;cnt<=r;cnt++){
    //     if((b[i]<=b[j] && i<=mid) || j>r){
    //         k[cnt]=b[i];
    //         i++;
    //     }
    //     else{
    //         k[cnt]=b[j];
    //         j++;
    //         ans+=mid-i+1;
    //     }
    // }
    // // for(int i=1;i<=3*n;i++){
    // //     cout<<k[i]<<' ';
    // // }
    // // cout<<endl;
    // // if()
    // for(int i=l;i<=r;i++){
    //     b[i]=k[i];
    // }
    // return;
    if (r - l <= 1)
    {
        return;
    }
    int mid = l + (r - l) / 2;
    mersort(l, mid);
    mersort(mid, r);
    int i = l, j = mid, cnt = l;
    while (cnt < r)
    {
        if (i >= mid || (j < r && b[i] > b[j]))
        {
            k[cnt++] = b[j++];
            ans += mid - i;
        }
        else
        {
            k[cnt++] = b[i++];
        }
    }
    for (int i = l; i < r; i++)
    {
        b[i] = k[i];
    }
}
// class T{
//     int cnt;
//     struct Tree{
//         int l,r,ch[2],mx;
//     };
//     void pushup(int rt){
//         t[rt].mx=max(t[rt>>1].mx,t[rt>>1|1].mx);
//     }
//     Tree t[qwe];
// public:
//     int build(int l,int r){
//         int rt=++cnt;
//         if(l==r){
//             t[rt].mx=a[l];
//             return rt;
//         }
//         int mid=(l+r)>>1;
//         t[rt].ch[0]=(l,mid);
//         t[rt].ch[1]=(mid+1,r);
//         pushup(rt);
//         return rt;
//     }
//     // int query(int rt,int l,int r,int loc){

//     //     if(l==r){

//     //     }
//     // }
// };
class Tree
{
    struct T
    {
        int l, r, mx;
    };
    T t[qwe];
    void pushup(int rt)
    {
        t[rt].mx = max(t[rt << 1].mx, t[rt << 1 | 1].mx);
    }

public:
    void build(int rt, int l, int r)
    {
        t[rt].l = l;
        t[rt].r = r;
        if (l == r)
        {
            t[rt].mx = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(rt << 1, l, mid);
        build(rt << 1 | 1, mid + 1, r);
        pushup(rt);
    }
    int query(int rt, int l, int r)
    {
        if (l <= t[rt].l && r >= t[rt].r)
        {
            return t[rt].mx;
        }
        int mid = (t[rt].l + t[rt].r) >> 1;
        int ans = INT_MIN;
        if (l <= mid)
        {
            ans = max(ans, query(rt << 1, l, r));
        }
        if (r > mid)
        {
            ans = max(ans, query(rt << 1 | 1, l, r));
        }
        return ans;
    }
};
Tree s;
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    // int ans=0;
    mersort(1, n + 1);
    // for(int i=1;i<=n;i++){
    //     printf("%d ",b[i]);
    // }
    // cout<<endl;
    // for(int i=1;i<=n;i++){
    //     for(int j=i;j<=n;j++){
    //         if((i>j)!=(a[i]>a[j]))
    //             ans++;
    //     }
    // }
    printf("%lld\n", ans);
    s.build(1, 1, n);
    for (int i = 1; i <= q; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", s.query(1, l, r));
    }
    return 0;
}