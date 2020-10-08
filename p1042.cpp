#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
char a[2505][30];
int main(){
    for (int i = 0; 1 ; i++)
    {
        for (int j = 0; 1 ; j++)
        {
            scanf("%c",&a[i][j]);
            if (a[i][j]=='E')
            {
                a[i][j]=0;
                break;
            }
        }
    }
    
    return 0;
}