// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e7 + 5;
int n, k, ans = INT_MAX;
int a[qwe], b[qwe];
deque<int> qa, qb;
int read()
{
    int x = 0, y = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
        {
            y = -1;
        }
        c = getchar();
    }
    // c = getchar();
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * y;
}
int main()
{
    freopen("/home/bai/code/9.in", "r", stdin);
    // scanf("%d%d", &n, &k);
    n = read(), k = read();
    for (int i = 1; i <= n; i++)
    {
        // scanf("%d", &a[i]);
        a[i] = read();
        // a[i]+=k;
    }
    for (int i = 1; i <= n; i++)
    {
        // scanf("%d", &b[i]);
        b[i] = read();
    }
    // printf("So Sad!");
    int l = 1, r = 0;
    while (r < n)
    {
        ++r;
        while (qa.size() && a[qa.back()] >= a[r])
        {
            qa.pop_back();
        }
        qa.push_back(r);
        while (qb.size() && b[qb.back()] <= b[r])
        {
            qb.pop_back();
        }
        qb.push_back(r);
        while (a[qa.front()] + k <= b[qb.front()] && l <= r)
        {
            ans = min(ans, r - l + 1);
            ++l;
            if (qa.size() && qa.front() < l)
                qa.pop_front();
            if (qb.size() && qb.front() < l)
                qb.pop_front();
        }
    }
    if (ans == INT_MAX)
    {
        printf("So Sad!\n");
    }
    else
    {
        printf("%d\n", ans);
    }
    return 0;
}