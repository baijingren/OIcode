#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
const int qwe=1e6+5;
bool vis[qwe];
int v[qwe];
int main(){
    freopen("test.in","w",stdout);
    for(int i=1;i<=1000;i++){
        int ans=1;
        memset(vis,0,sizeof(vis));
        for(int j=1;j<=i;j++){
            int k=(int)floor(double(i)/double(j));
            if(!vis[k]){
                vis[k]=1;
                ans++;
            }
        }
        v[ans]++;
        printf("%d\n",ans,i);
        // sleep(1);
    }
    printf("........................\n");
    for(int i=2;v[i]!=0;i++){
        printf("%d\n",v[i]);
    }
}