#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int T,n,m;

int u[qwe],l[qwe];
int main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            l[i]=0;
        }
        // ans1/=2;
        for(int i=1;i<=m;i++){
            u[i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char c;
                cin>>c;
                if(c=='.'){
                    continue;
                }
                else if(c=='#'){
                    l[i]++;
                    u[j]++;
                }
                else{
                    j--;
                }
            }
        }
        // for(int i=1;i<=n;i++){
        //     cerr<<l[i]<<endl;
        // }
        int ans1=0,ans2=0,cnt=0;
        for(int i=1;i<=n;i++){
            if(l[i]==1){
                ans1+=i;
                cnt++;
            }
        }
        ans1/=cnt;
        cnt=0;
        for(int i=1;i<=m;i++){
            if(u[i]==1){
                ans2+=i;
                cnt++;
            }
        }
        ans2/=cnt;
        cout<<ans1<<' '<<ans2<<endl;
    }
    return 0;
}