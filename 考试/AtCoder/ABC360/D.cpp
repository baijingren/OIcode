#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
#define ll long long
int n;
ll T;
int a[qwe];
ll neg[qwe],pos[qwe];
int top_neg=0,top_pos=0;
ll ans = 0;
deque<int> q;
int main(){
    scanf("%d%lld",&n,&T);
    for(int i=1;i<=n;i++){
        scanf("%1d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        int d;
        scanf("%d",&d);
        if(a[i] == 1){
            pos[++top_pos] = d;
        }
        else{
            neg[++top_neg] = d;
        }
    }
    sort(pos+1,pos+top_pos+1,[](int x,int y){
        return x<y;
    });
    sort(neg+1,neg+top_neg+1,[](int x,int y){
        return x<y;
    });
    // for(int i=1;i<=top_pos;i++){
    //     cerr<<pos[i]<<' ';
    // }
    // cerr<<endl;
    // for(int i=1;i<=top_neg;i++){
    //     cerr<<neg[i]<<' ';
    // }
    // cerr<<endl;
    q.push_front(1);
    int tr = 0;
    for(int i=1;i<=top_neg;i++){
        if(neg[i]>=pos[1]){
            tr = i;
            break;
        }
    }
    for(int i=tr;i<=top_neg;i++){
        int tmp = q.front();
        while(q.size() && pos[q.back()] < neg[i] - 2*T){
            q.pop_back();
        }
        for(int j=tmp+1;j<=top_pos;j++){
            if(pos[j]<=neg[i] && pos[j]>=neg[i]-2*T)
                q.push_front(j);
            else
                break;
        }
        ans+=q.size();
        // cerr<<q.size()<<endl;
    }
    cout<<ans<<endl;
    return 0;
}