#include<bits/stdc++.h>
using namespace std;
const int qwe=1e7+5;
// typedef long long ll;
int n,m,q,u,v,t,cnt=0,bnt=0;
int a[qwe*2],s[qwe],b[qwe*2];
priority_queue<int> que;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    scanf("%d%d%d%d%d%d",&n,&m,&q,&u,&v,&t);
    // cnt=n;
    double p=(double)u/v;
    if(p<0.5){
        p=1.0-p;
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        que.push(a[i]);

    }
    // int qnt=0;
    for(int i=1;i<=m;i++){
        int z=que.top();
        b[++bnt]=z;
        que.pop();
        int x=z*p,y=z-x;
        que.push(x);
        que.push(y);
    }
    while(que.size()){
        a[++cnt]=que.top();
        que.pop();
    }
    for(int i=t;i<=m;i+=t){
        printf("%d ",b[i]);
    }
    printf("\n");
    for(int i=t;i<=n+m;i+=t){
        printf("%d ",a[i]);
    }
}