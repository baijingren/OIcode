#include<bits/stdc++.h>
#define ll long long
#define un unsigned
using namespace std;
const int qwe=1e6+5;
int T;
int n,c;
int a[qwe];
int t[qwe],s[qwe];

int main(){
    scanf("%d",&T);
    while(T--){
        for(int i=1;i<=c;i++){
            a[i]=s[i]=t[i]=0;
        }
        scanf("%d%d",&n,&c);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            t[a[i]]++;
        }
        sort(a+1,a+n+1);
        for(int i=1;i<=c;i++){
            s[i]=s[i-1]+t[i];
        }
        bool f=0;
        for(int i=2;i<=c;i++){
            if(t[i]){
                for(int j=1;j<=c/i;j++){
                    int l=i*j,r=min(i*(j+1)-1,c);
                    if(s[l-1]!=s[r]){
                        if(t[j]==0){
                            f=1;
                            break;
                        }
                    }
                }
            }
            if(f==1){
                break;
            }
        }
        if(f==0){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}