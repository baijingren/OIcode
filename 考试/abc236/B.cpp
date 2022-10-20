#include<bits/stdc++.h>
using namespace std;
const int qwe=1e5+5;
int n,a;
int s[qwe];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=4*n-1;i++){
        scanf("%d",&a);
        s[a]++;
    }
    for(int i=1;i<=n;i++){
        if(s[i]!=4){
            printf("%d\n",i);
            return 0;
        }
    }
}