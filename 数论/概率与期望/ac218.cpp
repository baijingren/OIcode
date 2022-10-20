#include<bits/stdc++.h>
using namespace std;
#define ld double
const int qwe=1e6+5;
int a[5],b[5];
ld f[16][16][16][16][5][5];
bool v[16][16][16][16][5][5];
ld fu(int a,int b,int c,int d,int x,int y){
    if(v[a][b][c][d][x][y]){
        return f[a][b][c][d][x][y];
    }
    if() return 0;
    if(a<13){
        fu(a+1,b,c,d,x,y);
    }
}
int main(){
    // scanf("%d%d%d%d",&a,&b,&c,&d);
    bool flag=0;
    int cnt=0;
    for(int i=1;i<=4;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=4;i++){
        cnt+=max(a[i]-13,0);
    }
    if(cnt>2){
        printf("-1.000");
        return 0;
    }
    ld ans=fu(0,0,0,0,0,0);
    printf("%.3lf",ans);
    return 0;
}