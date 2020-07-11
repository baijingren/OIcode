#include<bits/stdc++.h>
using namespace std;
int a;
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d", &a);
    if (a == 0||a == 1)
    {
        printf("Today, I ate %d apple.", a);
    }
    else
    {
        printf("Today, I ate %d apples.", a);
    }
    
    return 0;
}