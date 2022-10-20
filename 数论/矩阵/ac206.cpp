#include<bits/stdc++.h>
using namespace std;
const int qwe=15;
int n,m,t,act;
int a[qwe*qwe];

struct Matrix{
    int r,c;
    int s[qwe][qwe];
};
Matrix I;
struct Node{
    string c;
    int len;
}op[qwe];

int pos(int x,int y){
    return x*m+y-m;
}
Matrix _pow()
int main(){
    scanf("%d%d%d%d",&n,&m,&t,&act);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%1d",&a[pos(i,j)]);
        }
    }
    for(int i=1;i<=act;i++){
        scanf("%s",op[i].c);
        op[i].len=op[i].c.length();
    }
    
    for(int i=1;i<=n;i++){

    }
}