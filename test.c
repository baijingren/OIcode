#include <stdio.h>
#include <math.h>
   //给项数做一个函数
int main (){
	double pai(int n);
	int n=1;
	double sum;
	double e;
	scanf ("%lf",&e);
	for(n = 1;;n++){
		sum = pai(n);
		if (sum>=e)
    	    break;
	} 
	if (fabs(pai(n-1)-e)<fabs(pai(n-2)-e)){
		printf ("%.9f %d",pai(n-1),n-1);       //小数点后9位有效数字
	} else {
    	printf ("%.9f %d",pai(n-2),n-2);      //为什么n-1和n-2 要清楚
	}
	return 0;
}
   

 double pai(int n) {
    double pi = 1.0;
    int i;
    for (i = 1; i <= n; i++)
	 {
        pi *= (2.0 * i) / (2.0 * i - 1) * (2.0 * i) / (2.0 * i + 1); //保证浮点数
    }
    return pi * 2; 
}
