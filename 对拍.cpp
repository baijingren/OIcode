#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
    int i;
    for (i=1;i<=1000;i++)
        {
            system("./make");
            system("./teacher");
            system("./p1164");
            printf("%d : ",i);
            if (system("diff test.out ab.out"))
                {
                    printf("WA\n");
                    return 0;
                }
            else printf("AC\n");
        }
    return 0;
}