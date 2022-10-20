#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int n,ans,cur;
int a[15][10005],len[15],st[15],pos[15][15],ht[15][15];
int t[15][15];
int f[(1<<10)+5][15][15][15][15];
int clac(int x,int y){
    if((st[x]&st[y])^st[y]){
        return INF;
    }
    int a=pos[y][ht[x][len[x]-1]];
    if(a==INF){
        return len[x];
    }
    int b,i;
    // for(i=len[x]-1;i>0;i--){
    //     if(pos[y][ht[x][i-1]]==INF || pos[y][ht[x][i-1]]>a){
    //         break;
    //     }
    //     a=pos[y][ht[x][i-1]];
    // }
    for(i=len[x]-1;i;i--){
        b=a;
        a=pos[y][ht[x][i-1]];
        if(a==INF || a>b){
            break;
        }
    }
    return i;
}
int main(){
    scanf("%d",&n);
    memset(pos,0x3f,sizeof(pos));
    memset(t,0x3f,sizeof(t));
    memset(f,0x3f,sizeof(f));
    for(int i=0;i<n;i++){
        int x,j=0;
        while(1){
            scanf("%d",&x);
            if(x==0){
                // j--;
                break;
            }
            ht[i][j]=--x;
            st[i]|=(1<<x);
            pos[i][x]=j++;
        }
        len[i]=j;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                t[i][j]=clac(i,j);
                // cout<<t[i][j]<<' ';
            }
        }
    }
    f[0][n][0][n][0]=0;
    for(int i=0;i<n;i++){
        f[1<<i][i][len[i]][n][0]=0;
    }
    ans=INF;
    for(int S=0;S<(1<<n);S++){
        for(int l=0;l<=n;l++){
            for(int i=len[l];i>=0;i--){
                for(int r=0;r<=n;r++){
                    for(int j=0;j<=len[r];j++){
                        // if((S & l) != 0 || (S & r) != 0){
                        if((cur=f[S][l][i][r][j])>=INF){
                            continue;
                        }
                        if(S==(1<<n)-1 && i==0 && j==len[r]){
                            if(ans>cur){
                                ans=cur;
                            }
                        }
                        for(int k=0;k<n;k++){
                            if(S>>k&1){
                                continue;
                            }
                            if(l!=n && i==0){
                                for(int x=t[k][l];x<=len[k];x++){
                                    if(f[S|(1<<k)][k][x][r][j]>cur){
                                        f[S|(1<<k)][k][x][r][j]=cur;
                                    }
                                }
                            }
                            if(r==n || j>=t[r][k]){
                                if(f[S|(1<<k)][l][i][k][0]>cur){
                                    f[S|(1<<k)][l][i][k][0]=cur;
                                }
                            }
                        }
                        if(l!=n && i==0){
                            if(f[S][n][0][r][j]>cur){
                                f[S][n][0][r][j]=cur;
                            }
                        }
                        int tem,temp;
                        for(int k=0;k<9;k++){
                            if(l==n){
                                tem=0;
                            }
                            else{
                                if(pos[l][k]>i){
                                    continue;
                                }
                                tem=(i-(pos[l][k]==i-1));
                            }
                            if(r==n){
                                temp=0;
                            }
                            else{
                                if(pos[r][k]>j){
                                    continue;
                                }
                                temp=(j+(pos[r][k]==j));
                            }
                            if(f[S][l][tem][r][temp]>cur+1){
                                f[S][l][tem][r][temp]=cur+1;
                            }
                        }
                        // }
                    }
                }
            }
        }
    }
    if(ans>=INF){
        ans=-1;
    }
    printf("%d\n",ans);
    return 0;
}