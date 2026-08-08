#include<bits/stdc++.h>
using namespace std;
int n,a,b,c,cnt=0;
int chk(int x,int y){
    if(x<y) return 1;
    else if(x>y) return 0;
    else return 2;
}
int main(){
    scanf("%d",&n);
    scanf("%d",&a);
    c=2;
    for(int i=2;i<=n;i++){
        scanf("%d",&b);
        if(c==2 && chk(a,b)!=2 && i==2){
            c=(chk(a,b)^1);
        }
        if(chk(a,b)!=(c^1)){
            cnt++;
            b=a;
            a=c?INT_MIN:INT_MAX;
        }
        else{
            swap(a,b);
        }
        c=chk(b,a);
    }
    printf("%d",cnt);
    return 0;
}