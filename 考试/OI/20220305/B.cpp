#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int num;
int n,m;
int ans[qwe];
struct Node{
    int x,y;
} a[qwe];
int solmn(){
    int nx=0,ny=INT_MAX;
    for(int i=1;i<=n;i++){
        nx=max(nx,a[i].x);
        ny=min(ny,a[i].y);
        if(nx>ny){
            return 0;
        }
    }
    return (ny-nx);
}
int solm4(){
    int sum=0;
    for(int i=1;i<=n;i++){
        if(m==1){
            // sum=max(a[i].y-a[i].x,sum);
            if(a[i].y-a[i].x>sum){
                sum=a[i].y-a[i].x;
                ans[1]=i;
            }
            continue;
        }
        for(int j=1;j<=n;j++){
            if(i==j){
                continue;
            }
            int nx=max(a[i].x,a[j].x);
            int ny=min(a[i].y,a[j].y);
            if(nx>ny){
                continue;
            }
            if(m==2){
                // sum=max(ny-nx,sum);
                if(ny-nx>sum){
                    sum=ny-nx;
                    ans[1]=i;
                    ans[2]=j;
                }
                continue;
            }
            for(int k=1;k<=n;k++){
                if(k==i || k==j){
                    continue;
                }
                nx=max(nx,a[k].x);
                ny=min(ny,a[k].y);
                if(nx>ny){
                    continue;
                }
                if(m==3){
                    // sum=max(ny-nx,sum);
                    if(ny-nx>sum){
                        sum=ny-nx;
                        ans[1]=i;
                        ans[2]=j;
                        ans[3]=k;
                    }
                    continue;
                }
                for(int l=1;l<=n;l++){
                    if(l==i || l==j || l==k){
                        continue;
                    }
                    nx=max(nx,a[l].x);
                    ny=min(ny,a[l].y);
                    if(nx>ny){
                        continue;
                    }
                    if(m==4)
                        if(ny-nx>sum){
                        sum=ny-nx;
                        ans[1]=i;
                        ans[2]=j;
                        ans[3]=k;
                        ans[4]=l;
                    }
                }
            }
        }
    }
    return sum;
}
int sol(){
    return 0;
}
int main(){
    scanf("%d",&num);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i].x,&a[i].y);
    }
    // sort(a+1,a+n+1,[](Node x,Node y){
    //     return x.x<y.x;
    // });
    if(num<=3){
        printf("%d\n",solmn());
        for(int i=1;i<=n;i++){
            printf("%d ",i);
        }
        return 0;
    }
    else if(m<=4){
        printf("%d\n",solm4());
        sort(ans+1,ans+m+1);
        for(int i=1;i<=m;i++){
            printf("%d ",ans[i]);
        }
        return 0;
    }
    else if(num>3 && num<7){
        printf("%d",sol());
        return 0;
    }
    return 0;
}