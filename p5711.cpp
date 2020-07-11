#include <bits/stdc++.h>
using namespace std;
int yr;
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d", &yr);
    if (yr % 4 == 0)
    {
        if (yr % 100 == 0&&yr%400!=0)
        {
            printf("0");
        }
        else
        {
            printf("1");
        }
    }

    return 0;
}