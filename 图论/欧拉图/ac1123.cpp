#include<bits/stdc++.h>
using namespace std;
double n,m,xa,ya,xb,yb;
double ans;
int main(){
   freopen("/home/bai/code/test.in","r",stdin);
    scanf("%lf%lf",&n,&m);
    while(~scanf("%lf%lf%lf%lf", &xa,&ya,&xb,&yb)) {
        double x=xa-xb;
        double y=ya-yb;
        ans+=sqrt(x*x+y*y);
    }
    ans*=2;
    ans/=1000;
    ans/=20;
    ans*=60;
//    cout<<ans<<' ';
    int h,mi;
    h=(int)ans/60;
    mi=(int)round(ans-h*60);
    // cout<<h<<':'<<mi<<endl;
    printf("%d:%02d",h,mi);
//    printf("%lf",ans);
    return 0;
}