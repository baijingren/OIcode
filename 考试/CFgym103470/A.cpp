#include<bits/stdc++.h>
using namespace std;
int n,a,b;
int main(){
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<n;i++) printf("%c",b<=(n/2)?'L':'R');
    for(int i=1;i<n;i++) printf("%c",a<=(n/2)?'U':'D');
    for(int i=1;i<=(a<=(n/2)?(a-1):(n-a));i++) printf("%c",a<=(n/2)?'D':'U');
    for(int i=1;i<=(b<=(n/2)?(b-1):(n-b));i++) printf("%c",b<=(n/2)?'R':'L');
    return 0;
}