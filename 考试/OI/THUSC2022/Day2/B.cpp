#include<bits/stdc++.h>
using namespace std;
const int qwe=1e4+5;
int n,m;
bool read(string &a){
    char c=getchar();
    while(c=='\ ' || c=='\t'){
        c=getchar();
    }
    while(c!=EOF){
        if(c=='\n' || c=='\r'){
            break;
        }
        a.push_back(c);
        c=getchar();
    }
    if(c==EOF){
        return 0;
    }
    return 1;
}
string a[25],c[qwe];
stack<int> s[25];
queue<int> q[25];
// map<string,bool> mp;
vector<int> e[qwe];
bool vis[qwe];
map<string,int> encode;
map<int,string> decode;
void add_edge(string a){
    int k=a.length(),fa,son;
    string temp;
    for(int i=0;i<k;i++){
        if(a[i]==','){
            fa=encode[temp];
            temp.clear();
            // cout<<fa<<' ';
            continue;
        }
        if(a[i]=='\ '){
            son=encode[temp];
            e[fa].push_back(son);
            temp.clear();
            continue;
        }
        else if(i==k-1){
            temp.push_back(a[i]);
            son=encode[temp];
            e[fa].push_back(son);
            temp.clear();
        }
        temp.push_back(a[i]);
    }
}
bool check_stack_empty(){
    int sum=0;
    for(int i=1;i<=n;i++){
        if(s[i].empty()){
            // return 0;
            sum++;
        }
    }
    if(sum==n){
        return 0;
    }
    return 1;
}
int main(){
    // freopen("B.in","r",stdin);
    scanf("%d%d ",&m,&n);
    for(int i=1;i<=n;i++){
        read(a[i]);
        // mp[a[i]]=1;
        // s[i].push(a);
    }
    for(int i=1;i<=m;i++){
        read(c[i]);
        string temp;
        for(int j=0;j<=8;j++){
            if(c[i][j]==','){
                encode[temp]=i;
                decode[i]=temp;
                temp.clear();
                break;
            }
            temp.push_back(c[i][j]);
        }
        // add_edge(c);
    }
    for(int i=1;i<=n;i++){
        s[i].push(encode[a[i]]);
        // cout<<encode[a[i]]<<' ';
    }
    for(int i=1;i<=m;i++){
        add_edge(c[i]);
    }
    while(check_stack_empty()){
        for(int i=1;i<=n;i++){
            if(s[i].empty()){
                continue;
            }
            int u=s[i].top();
            s[i].pop();
            while(!s[i].empty() && vis[u]){
               u=s[i].top();
               s[i].pop(); 
            }
            if(vis[u]){
                continue;
            }
            vis[u]=1;
            q[i].push(u);
            for(int v:e[u]){
                s[i].push(v);
            }
        }
    }
    for(int i=1;i<=n;i++){
        while(!q[i].empty()){
            int k=q[i].front();
            q[i].pop();
            string temp=decode[k];
            cout<<temp;
            if(!q[i].empty()){
                cout<<',';
            }
        }
        cout<<endl;
    }
    return 0;
}