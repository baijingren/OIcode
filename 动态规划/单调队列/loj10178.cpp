#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
typedef long long ll;
int n,m;
ll a[qwe],d[qwe],s[qwe],q[qwe*2],ans[qwe];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i],&d[i]);
        a[i+n]=a[i];
        d[i+n]=d[i];
    }
    for(int i=1;i<=n;i++){
        s[i]=s[i+n]=a[i]-d[i];
    }
    for(int i=1;i<=n*2;i++){
        s[i]+=s[i-1];
    }
    int hd=0,ed=-1;
    for(int i=n*2;i>=1;i--){
        if(hd<=ed && q[hd]>=1+n){//q:queue;;hd,ed:front,back
            hd++;
        }
        while(hd<=ed&&s[q[ed]]>=s[i]){//xian
            ed--;
        }
        q[++ed]=i;
        if(i<=n){//hou
            if(s[q[hd]]>=s[i-1]) ans[i]=1;
        }
    }
    d[0]=d[n];
    for(int i=1;i<=n;i++){
        s[i]=s[i+n]=a[i]-d[i];
    }
    for(int i=1;i<=n*2;i++){
        s[i]+=s[i-1];
    }
    for(int i=1;i<=n*2;i++){
        if(hd<=ed&&q[hd]<i-n) hd++;
        if(i>n){
            if(s[q[hd]]<=s[i]) ans[i-n]=1;//错误：i-i
        }
        while(hd<=ed&&s[q[ed]]>=s[i]){
            ed--;
        }
        q[++ed]=i;
    }
    for(int i=1;i<=n;i++){
        if(ans[i]) puts("TAK");
        else puts("NIE");
    }
}