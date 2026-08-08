#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int qwe = 1e6 + 5;
ull hsh, hah;
char base[27], a[27], ele[qwe], cmp[qwe];
ull fpow(int x, int al)
{
    ull tmp = x;
    ull ans = 1;
    while (al)
    {
        if (al & 1)
        {
            ans = ans * tmp;
        }
        tmp = tmp * tmp;
        al >>= 1;
    }
    return ans;
}
void has(char c[], char s[])
{
    int n = strlen(c + 1);
    for (int i = 1; i <= n; i++)
    {
        hsh = hsh * 131 + c[i] - 'a' + 1;
    }
    for (int i = n; i >= 1; i--)
    {
        hah = hah * 131 + s[i] - 'a' + 1;
    }
}
void print(int x, int n)
{
    printf("%d %d ", x, n);
    for (int i = 1; i <= x; i++)
    {
        printf("%c", a[i]);
    }
    for (int i = 1; i <= x; i++)
    {
        printf("%c", a[i]);
    }
}
int main()
{
    scanf("%s", base + 1);
    scanf("%s", ele + 1);
    int n = strlen(ele + 1);
    for (int i = 1; i <= 27; i++)
    {
        a[base[i] - 'a' + 1] = 'a' + i - 1;
    }
    for (int i = 1; i <= n; i++)
    {
        cmp[i] = a[ele[i]];
    }
    has(cmp, ele);
    for (int i = n; i >= n / 2; i--)
    {
        ull ff = fpow(131, i);
        if (hah % ff == hsh % ff)
        {
            print(n - i + 1, i);
            printf("\n");
        }
    }
}