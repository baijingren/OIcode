#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define random(x,y) (rand()%(y-x)+(x-1)+1)

int main()
{
    freopen("test.in", "w", stdout);
    srand((int)time(0));
    int x = random(1,100);
    int y = random(1, 1000);
    printf("%d %d\n", x, y);
    for (int i = 0; i < x; i++)
    {
        printf("%d ", random(1,1000));
    }
    return 0;
}
