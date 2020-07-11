#include<bits/stdc++.h>
using namespace std;
char a[105];
int s;
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%s", a);
    s = strlen(a);
    for (int i = 0; i < s; i++)
    {
        if (a[i]>='a'&&a[i]<='z')
        {
            a[i] = a[i] - ('a' - 'A');
        }
    }
    printf("%s", a);
    return 0;
}