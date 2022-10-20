#include<bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(NULL));
    int x = rand() % 10 + 1;
    for (int i = 1; i <= x; i++)
    {
        printf("%d ", rand() % 100 + 1);
    }
    return 0;
}