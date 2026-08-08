#include<bits/stdc++.h>
using namespace std;
const int qwe=105;
int n,s1,s2,d,cnt=0;
int a[qwe];
int chk(int x){
    int ans=0;
    while(x){
        if(x>=10){
            ans+=x%10;
            x/=10;
        }
        else{
            ans+=x;
            x=0;
        }
    }
    return ans;
}
int cal(){
    int b[105],sum=0;
    memset(b,0,sizeof(b));
        // cerr<<"possible ans:";
    for(int i=1;i<=n;i++){
        // int s=a[i]*d;
        b[i]+=a[i]*d;
        // cerr<<a[i];
        if(b[i]>=10){
            b[i+1]+=b[i]/10;
            b[i]%=10;
        }
        // b[i]+=s;
    }
    // cerr<<endl;
    // cerr<<"b:";
    for(int i=1;i<=n+1;i++){
        // cerr<<b[i]<<' ';
        sum+=b[i];
    }
    // cerr<<endl<<"sum:"<<sum<<endl;
    return sum;
}
void print(){
    for(int i=n;i>=1;i--){
        printf("%d",a[i]);
    }
    cerr<<cnt<<endl;
    exit(0);
}
bool dfs(int x,int sum){
    cnt++;
    if(x<=0){
        return 0;
    }
    for(int i=(x==n?1:0);i<=9;i++){
        // int k=chk(i*d);
        // cerr<<x<<" i:"<<i<<" i+sum:"<<i+sum<<endl;
        a[x]=i;
        if((x-1)*9<(s1-sum-i)){
            // return 0;
            continue;
        }
        if((x-1)*9==(s1-sum-i)){
            // cerr<<"I am here."<<endl;
            for(int i=x-1;i>=1;i--){
                a[i]=9;
            }
            int k=cal();
            // cerr<<k<<endl;
            if(k==s2){
                // cout<<k<<endl;
                print();
            }
        }
        if(i+sum==s1 && x==1){
            // if(k+sum2==s2){
            //     a[x]=i;
            //     return 1;
            // }
            int k=cal();
            if(k==s2){
                print();
            }
        }
        if(i+sum>s1){
            // return 0;
            break;
            // continue;
        }
        if(dfs(x-1,i+sum)){
            return 1;
        }
        // else return 0;
    }
    return 0;
}
int main(){
    freopen("math.in","r",stdin);
    freopen("math.out","w",stdout);
    freopen("math.err","w+",stderr);
    scanf("%d%d%d%d",&n,&s1,&s2,&d);
    dfs(n,0);
    // if(s1<=(n*9-8)){
    //     dfs(n-1,1);
    // }
    // else{
    //     dfs(n-1,((n*9)-s1));
    // }
    // for(int i=n;i>=1;i--){
    //     printf("%d",a[i]);
    // }
    cerr<<cnt<<endl;
    printf("Cirno is too smart");
    return 0;
}