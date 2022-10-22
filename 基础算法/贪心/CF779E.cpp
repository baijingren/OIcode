#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,m,k;
int la[qwe],c[qwe];
int lb[qwe],a,b;
int pos[qwe];
vector<int> AB,A,B,NU;
bool cmp(int a,int b){
    return c[a]<c[b];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>la[i];
        pos[la[i]]=1;
    }
    cin>>b;
    for(int i=1;i<=b;i++){
        cin>>lb[i];
        if(pos[lb[i]]){
            AB.push_back(lb[i]);
            pos[lb[i]]=3;
        }
        else{
            B.push_back(lb[i]);
            pos[lb[i]]=1;
        }
    }
    for(int i=1;i<=n;i++){
        if(pos[i]==1){
            A.push_back(i);
        }
        else if(pos[i]==0){
            NU.push_back(i);
        }
    }
    sort(A.begin(),A.end(),cmp);
    sort(B.begin(),B.end(),cmp);
    sort(AB.begin(),AB.end(),cmp);
    sort(NU.begin(),NU.end(),cmp);
    int lim=min(m,(int)AB.size());
    for(int i=1;i<=m;i++){
        if(k>=i){
            
        }
    }
}