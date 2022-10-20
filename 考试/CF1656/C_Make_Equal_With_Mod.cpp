#include<bits/stdc++.h>
#define ll long long
#define un unsigned
using namespace std;
const int qwe=1e6+5;
int T;
int n,m;
int a[qwe];
map<int,int> mp;
int main(){
    //freopen("/home/bai/code/test.in","r",stdin);
    //freopen("/home/bai/code/test.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int f=0,ff=0,x;
        mp.clear();
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            if((mp[x+1] || mp[x-1])){
                f=1;
            }
            if(x==1){
                ff=1;
            }
            mp[x]=1;
        }
        if(f & ff){
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
    }
    return 0;
}