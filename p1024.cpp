#include <bits/stdc++.h>
using namespace std;
float a, b, c, d;
map<double, int> v;
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%f%f%f%f", &a, &b, &c, &d);
    for (double i = -100; i <= 100; i = i + 0.001)
    {
        double j = i + 0.001;
        double y1 = a * i * i * i + b * i * i + c * i + d;
        double y2 = a * j * j * j + b * j * j + c * j + d;
        if (y1 >= 0 && y2 <= 0 || y1 <= 0 && y2 >= 0)
        {
            double x = (i + j) / 2;
            if (v[x] != 1)
            {
                printf("%.2lf ", x);
                v[x] = 1;
            }
        }
    }
    return 0;
}