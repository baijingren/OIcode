#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
char c[qwe];
int a,b;
int main(){
    scanf("%s",c+1);
    scanf("%d%d",&a,&b);
    char k=c[a];
    c[a]=c[b];
    c[b]=k;
    printf("%s",c+1);
    return 0;
} 