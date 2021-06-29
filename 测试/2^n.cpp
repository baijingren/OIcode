#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("/home/bai/code/test.out", "w", stdout);
    int x = 1;
    for (int i = 1; i <= 20; i++)
    {
        x <<= 1;
        printf("%d, ", x);
    }
    return 0;
}