#include<bits/stdc++.h>
using namespace std;
const int qwe=100005;
int n,m;
long long mod=1e9+7;
int fa[qwe][25];
int fnd(int x,int len){
    if(fa[x][len]==x) return x;
    return fa[x][len]=fnd(fa[x][len],len);
}
void add(int la,int lb,int len){
    int x=fnd(la,len),y=fnd(lb,len);
    if(x==y) return;
    fa[fa[la][len]][len]=fa[lb][len];
}
long long po(int x, int k)
{
	long long ans = 1;
	for ( ; k; k >>= 1, x *= x)
	    if (k & 1){
	        ans *= x;
            ans%=mod;
        }
	return ans;
} 
int main(){
    freopen("/home/bai/code/test.in", "r", stdin);
    scanf("%d%d",&n,&m);
    for(int j=0;j<=20;j++){
        for(int i=1;i<=n;i++){
            fa[i][j]=i;
        }
    }
    for(int i=1;i<=m;i++){
        int la,ra,lb,rb;
        scanf("%d%d%d%d",&la,&ra,&lb,&rb);
        // add(la,ra,lb,rb);
        for(int j=20;j>=0;j--){
            if(la+(1<<j)-1<=ra){
                add(la,lb,j);
                la+=(1<<j);
                lb+=(1<<j);
            }
        }
    }
    for(int j=20;j>0;j--){
        for(int i=1;i<=n-(1<<j)+1;i++){
            add(i,fnd(i,j),j-1);
            add(i+(1<<(j-1)),fa[i][j]+(1<<(j-1)),j-1);
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(fnd(i,0)==i){
            cnt++;
        }
    }
    // printf("%lld",(9*po(10,cnt))%mod);
    long long int ans=9ll;
    for(int i=1;i<cnt;i++){
        ans*=10ll;
        ans%=mod;
    }
    printf("%lld",ans);
    return 0;
}