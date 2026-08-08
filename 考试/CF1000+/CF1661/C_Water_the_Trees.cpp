#include<bits/stdc++.h>
#define ll long long
#define un unsigned
using namespace std;
const int qwe=1e6+5;
int T;
int n,m;
int a[qwe],t[qwe],f[qwe];

int main(){
    //freopen("/home/bai/code/test.in","r",stdin);
    //freopen("/home/bai/code/test.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int mx=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            f[i]=t[i]=0;
            // mx=max(mx,a[i]);
        }
        int _t=0,_f=0,ans;
        sort(a+1,a+n+1);
        for(int i=1;i<n;i++){
            // cout<<0;
            if((a[n]-a[i])%3==0){
                int k=(a[n]-a[i])/3;
                t[i]+=k;
                f[i]+=k;
            }
            else if((a[n]-a[i])%3==1){
                int k=((a[n]-a[i])-1)/3;
                t[i]+=k;
                f[i]+=k;
                f[i]++;
            }
            else if((a[n]-a[i])%3==2){
                int k=((a[n]-a[i])-2)/3;
                t[i]+=k;
                f[i]+=k;
                t[i]++;
            }
            _t+=t[i];
            _f+=f[i];
        }
        // cout<<_f<<' '<<_t<<' ';
        for(int i=1;i<=n;i++){
            while(f[i]>=2){
                // cout<<1;
                if(abs(_f-3-_t)<abs(_f-_t)){
                    f[i]-=2;
                    _f-=2;
                    _t++;
                    t[i]++;
                }
                else{
                    break;
                }
            }
        }
        if(_t>=_f){
            ans=_t*2;
        }
        else{
            ans=_f*2-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}