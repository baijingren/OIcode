#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,m,cnt=0;
int a[qwe],b[qwe],c[qwe];
// int mp[int(1e9+5)];
map<int,int> mp;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        mp[a[i]]=i;
    }
    for(int i=1;i<=m;i++){
        int k;
        scanf("%d",&k);
        b[i]=mp[k];
    }
    for(int i=1;i<=m;i++){
        if(!b[i]) continue;
        if(c[cnt]<b[i]){
            c[++cnt]=b[i];
        }
        else{
            int k=lower_bound(c+1,c+cnt+1,b[i])-c;
            c[k]=b[i];
        }
    }
    printf("%d",cnt);
    return 0;
}