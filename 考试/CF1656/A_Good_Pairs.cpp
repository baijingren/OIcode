    #include<bits/stdc++.h>
    #define ll long long
    #define un unsigned
    using namespace std;
    const int qwe=1e6+5;
    int T;
    int n,m;
    // int a[qwe];
    struct Node{
        int num,id;
    } a[qwe];

    int main(){
        //freopen("/home/bai/code/test.in","r",stdin);
        //freopen("/home/bai/code/test.out","w",stdout);
        scanf("%d",&T);
        while(T--){
            scanf("%d",&n);
            for(int i=1;i<=n;i++){
                scanf("%d",&a[i].num);
                a[i].id=i;
            }
            sort(a+1,a+n+1,[](Node a,Node b){
                return a.num>b.num;
            });
            int ans1=min(a[n].id,a[1].id);
            int ans2=max(a[n].id,a[1].id);
            printf("%d %d\n",ans1,ans2);
        }
        return 0;
    }