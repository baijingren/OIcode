#include<bits/stdc++.h>
using namespace std;
const int qwe=2e6+5;
int T;
int n;
struct per{
    int num,id;
    // bitset<qwe> pro;
    vector<int> pro;
}a[qwe];
int v[qwe];
// bitset<qwe> k;
int main(){
    freopen("discuss1.in","r",stdin);
    // freopen("discuss.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            v[i]=0;
        }
        for(int i=1;i<=n;i++){
            // int x;
            a[i].pro.clear();
            scanf("%d",&a[i].num);
            if(a[i].num==0){    
                a[i].pro.push_back(0);
            }
            for(int j=1;j<=a[i].num;j++){
                int y;
                scanf("%d",&y);
                a[i].pro.push_back(y);
            }
            a[i].id=i;
        }
        sort(a+1,a+n+1,[](per a,per b){
            return a.num>b.num;
        });
        int ans1=0,ans2=0;
        for(int i=1;i<=n;i++){
            // int col=0;
            int col=v[a[i].pro[0]];
            for(int j:a[i].pro){
                if(col!=v[j]){
                    ans1=max(col,v[j]);
                    ans2=i;
                    break;
                }
                // v[j]=i;
            }
            for(int j:a[i].pro){
                v[j]=i;
            }
            if(ans1 && ans2){
                break;
            }
        }
        if(!ans1 && !ans2){
            printf("NO\n");
        }
        else{
            printf("YES\n");
            printf("%d %d\n",a[ans1].id,a[ans2].id);
        }
    }
    return 0;
}