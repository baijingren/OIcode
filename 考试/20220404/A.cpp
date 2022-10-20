#include<bits/stdc++.h>
using namespace std;
int n;
const int qwe=1e6+5;
int a[qwe],v[qwe],p[qwe],cnt=0,b[qwe];
int t[qwe],s[qwe];
map<int,int> mp;
void shai(int x){
    for(int i=2;i<=x;i++){
        if(!v[i]){
            p[++cnt]=i;
            v[i]=i;
        }
        for(int j=1;j<=cnt;j++){
            if(p[j]*i>x || p[j]>v[i]){
                break;
            }
            v[i*p[j]]=p[j];
        }
    }
    // if(lo){
        for(int i=1;i<=cnt;i++){
            s[i]=p[i]*p[i];
            t[i]=p[i]*s[i];
        }
    // }
}
int work(int x){
    for(int i=1;i<=cnt;i++){
        while(x%t[i]==0){
            x/=t[i];
        }
    }
    return x;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    shai(1290);
    int mx=0;
    for(int i=1;i<=n;i++){
        a[i]=work(a[i]);
        mp[a[i]]++;
        mx=max(mx,a[i]);
    }
    int ans=0;
    // shai(qwe/1000);
    shai(sqrt(mx));
    for(int i=1;i<=n;i++){
        if(a[i]!=1 && mp[a[i]]!=-1){
            int k=-1,temp=a[i];
            long long sv=1;
            for (int j = 1; j <= cnt; j++) {
                if (temp % s[j] == 0){
                    sv *= p[j], temp /= s[j];
                }
                else if (temp % p[j] == 0){
                    sv *= p[j] * p[j], temp /= p[j];
                }
                if (sv > mx){
                    break;
                }
            }
            if (temp == 1){
                k=int(sv);
            }
            ans+=max(mp[a[i]],mp[k]);
            mp[a[i]]=-1;
            mp[k]=-1;
        }
    }
    printf("%d\n",ans+(mp[1]>0));
    return 0;
}