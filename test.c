#include <stdio.h>

int main()
{
    double x;
    int n;
    scanf("%lf%d", &x, &n);
    double result = 0.0;
    double term = x;
    double factorial = 1.0;
    for (int i = 1; i <= n; i++)
    {
        result += term;
        term = (-1) * term * x * x / ((2 * i) * (2 * i + 1));
    }
    printf("%.8lf", result);
    return 0;
}
/*
0.5236 4
0.5236 50
*/