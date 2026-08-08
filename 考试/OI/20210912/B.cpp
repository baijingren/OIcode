#include<bits/stdc++.h>
using namespace std;
const int qwe=100005;
int n,hmax=0,hd=-1,ans=0;
int h[qwe];
deque<int> q;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&h[i]);
        hmax=max(hmax,h[i]);
    }
    q.push_back(h[1]);
    h[1]=0;
    ans=1;
    hd=q.front();
    for(int j=1;j<=hmax;j++){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(j==1&&i==1) continue;
            if(h[i]==0){
                cnt++;
                q.clear();
                hd=-1;
                continue;
            }
            while(q.size()&&h[i]<q.back()){
                q.pop_back();
            }
            q.push_back(h[i]);
            h[i]-=q.front();
            if(hd!=q.front()){
                ans++;
            }
                // cout<<' '<<hd<<endl;
            hd=q.front();
        }
        if(cnt==n){
            break;
        }
        q.clear();
        hd=-1;
    }
    printf("%d",ans);
}