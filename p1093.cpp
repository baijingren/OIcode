#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct stu
{
    int chi,eng,mat,ans,num;
};
stu st[400];
int n,yw,sx,yy,zf,xh;
bool cmp(const stu &x,const stu &y){
if(x.ans<y.ans) return 0;
else if(x.ans>y.ans) return 1;
else if(x.chi<y.chi) return 0;
else if(x.chi>y.chi) return 1;
else if(x.num>y.num) return 0;
else if(x.num<y.num) return 1;
}
int main(){
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d",&yw,&sx,&yy);
        st[i].chi=yw;
        st[i].mat=sx;
        st[i].eng=yy;
        st[i].ans=yw+sx+yy;
        st[i].num=i;
    }
    sort(st,st+n,cmp);
    for (int i = 0; i < 5; i++)
    {
        zf=st[i].ans;
        xh=st[i].num;
        printf("%d %d\n",xh+1,zf);
    }
    return 0;
}
