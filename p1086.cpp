#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int m,n,k,t,p,tim;
struct hua
{
    int plx,ply,num;
};
hua hu[50000];
inline bool cmp(const hua &u,const hua &v){
	return u.num >v.num ;
}
int main(){
    scanf("%d%d%d",&m,&n,&k);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d",&p);
            hu[++t].num=p;
            hu[t].plx=j;
            hu[t].ply=i;
        }
    }
    sort(hu+1,hu+n*m+1,cmp);
    tim+=hu[1].plx+1;
    int i=1,ans=0;
    while(tim+hu[i].plx<=k)
    {
        ans+=hu[i++].num;
        tim+=abs(hu[i].plx-hu[i-1].plx)+abs(hu[i].ply-hu[i-1].ply)+1;
    }
    printf("%d",ans);
    return 0;
}