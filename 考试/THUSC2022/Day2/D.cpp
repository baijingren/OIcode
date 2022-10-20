#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
#define PII pair<int,int>
#define MP make_pair
const double d=0.9;
const double eps=1e-8;
const int qwe=1e3+5;
int n,st;
bool vis[qwe],no_start=0;
double las;
vector<int> e[qwe];
vector<int> ed[qwe];
double pr[qwe];
queue<int> q;
void sol(){
    for(int i=1;i<=n;i++){
        vis[i]=0;
    }
    while(!q.empty()) q.pop();
    for(int i=1;i<=n;i++){
        if(ed[i].size()==0){
            q.push(i);
            vis[i]=1;
        }
    }
    if(q.empty()){
        no_start=1;
    }
    if(no_start){   
        int k=rand()%n/2+1;
        q.push(k);
        vis[k]=1;
        // cout<<k<<' '<<st<<endl;
        // usleep(30);
        // int a=1;
        // for(int i=1;i<=n;i++){
        //     a++;
        //     a--;
        // }
    }
    // cout<<2;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        pr[u]=0;
        for(auto v:ed[u]){
            pr[u]+=pr[v]/(double)e[v].size();
        }
        pr[u]*=d;
        pr[u]+=(1.0-d)/(double)n;
        for(auto v:e[u]){
            if(vis[v]){
                continue;
            }
            vis[v]=1;
            q.push(v);
        }
    }
}
int main(){
    // freopen("D.in","r",stdin);
    // usleep(200);
    srand(time(NULL));
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            // e[i].push_back(j);
            int x;
            scanf("%d",&x);
            if(x){
                e[i].push_back(j);
                ed[j].push_back(i);
            }
        }
    }
    st=rand()%n+1;
    for(int i=1;i<=n;i++){
        pr[i]=(1.0/double(n));
    }
    int cnt=1;
    while(fabs(pr[st]-las)>eps && cnt<20*n){
        las=pr[st];
        sol();
        // cout<<1;
        cnt++;
    }
    for(int i=1;i<=n;i++){
        printf("%lf\n",pr[i]);
    }
    return 0;
}