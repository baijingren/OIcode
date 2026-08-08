#include<bits/stdc++.h>
using namespace std;
int aa,ab,ac,ad;
int ba,bb,bc;
int main(){
    scanf("%d%d%d%d",&aa,&ab,&ac,&ad);
    scanf("%d%d%d",&ba,&bb,&bc);
    int ans=min({aa,ab,ac,ad})+min({ba,bb,bc});
    printf("%d",ans);
}