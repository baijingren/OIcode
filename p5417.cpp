#include<bits/stdc++.h>
using namespace std;
int m;
double h;
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d%lf", &m, &h);
    double s = m / (h * h);
    if (s < 18.5)
    {
        printf("Underweight");
    }
    else if (s >=18.5 && s<24)
    {
        printf("Normal");
    }
    else
    {
        cout << s;
        printf("Overweight");
    }
    return 0;
}