#include<bits/stdc++.h>
using namespace std;
#define ll __int128_t
const int qwe=1e6+5;
int n,m;
ll a[qwe];
int ans[qwe];
map<int,bool> mp;
void ed(int x){
    for(int i=x+1;i<=n;i++){
        ans[i]=n-i+1;
    }
}
int main(){
    freopen("aplusb.in","r",stdin);
    freopen("aplusb.out","w",stdout);
    cin>>n>>m;
    a[0]=1;
    for(int i=1;i<=n;i++){
        a[i]=a[i-1]*i;
    }
    if(a[n]<=0){
        cout<<"fen bu yao le\n";
        return 0;
    }
    int s=m;
    for(int i=n;i>=1;i--){
        if(1.0*s/a[i-1]<1.0){
            ans[n-i+1]=1;
        }
        else{
            ans[n-i+1]=(int)ceil(1.0*s/a[i-1]);
            s%=a[i-1];
            // s+=1;
            if(s==0){
                ed(n-i+1);
                break;
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     cerr<<ans[i]<<' ';
    // }
    mp[0]=1;
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=ans[i];j++,cnt++){
            while(mp[cnt]){
                cnt++;
            }
        }
        cnt--;
        mp[cnt]=1;
        ans[i]=cnt;
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
/*
1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
1 4 2 3
1 4 3 2
2 1 3 4
2 1 4 3
2 3 1 4
2 3 4 1
2 4 1 3
2 4 3 1
3 1 2 4
3 1 4 2
3 2 1 4
3 2 4 1
3 4 1 2
3 4 2 1
4 1 2 3
4 1 3 2
4 2 1 3
4 2 3 1
4 3 1 2
4 3 2 1
*/