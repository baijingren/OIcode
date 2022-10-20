#include<bits/stdc++.h>
using namespace std;
const int qwe=3e6+5;
int n,T,m,id=0;
char a[qwe],mp[256];
struct Trie{
    int tg[qwe],nxt[qwe][63],cnt;
    void init(){
        for(int i=0;i<=cnt;i++){
            tg[i]=0;
            for(int j=0;j<=62;j++){
                nxt[i][j]=0;
            }
        }
        cnt=0;
    }
    void insert(char *c,int l){
        int p=0;
        for(int i=0;i<l;i++){
            int k=mp[c[i]];
            if(!nxt[p][k]){
                nxt[p][k]=++cnt;
            }
            p=nxt[p][k];
            tg[p]++;
        }
    }
    int query(char *c,int l){
        int p=0;
        for(int i=0;i<l;i++){
            int k=mp[c[i]];
            if(!nxt[p][k]){
                return 0;
            }
            p=nxt[p][k];
        }
        return tg[p];
    }
} t;
int main(){
    scanf("%d",&T);
    for(char i='a';i<='z';i++) mp[i]=++id;
	for(char i='A';i<='Z';i++) mp[i]=++id;
	for(char i='0';i<='9';i++) mp[i]=++id;
    while(T--){
        scanf("%d%d ",&n,&m);
        t.init();
        for(int i=1;i<=n;i++){
            scanf("%s",a);
            t.insert(a,strlen(a));
        }
        for(int i=1;i<=m;i++){
            scanf("%s",a);
            int ans=t.query(a,strlen(a));
            printf("%d\n",ans);
        }
    }
    return 0;
}