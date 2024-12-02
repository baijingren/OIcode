#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int n,m;
char s[qwe],t[qwe];
int vis[30];
int main(){
    cin>>s>>t;
    n = strlen(s);
    m = strlen(t);
    for(int i=0;i<n;i++){
        int a = s[i] - 'a' + 1;
        vis[a]++;
    }
    bool flag = 0;
    for(int i=0;i<m;i++){
        int a = t[i] - 'a' + 1;
        if(vis[a] == 0){
            cout<<"No"<<endl;
            flag = 1;
            break;
        }
        else if((s[n-1] - 'a' + 1) == a && vis[a] == 1){
            cout<<"No"<<endl;
            flag = 1;
            break;
        }
        else if((s[0] - 'a' + 1) == a && vis[a] == 1){
            cout<<"No"<<endl;
            flag = 1;
            break;
        }
        else if((s[n-1] - 'a' + 1) == a && (s[0] - 'a' + 1) == a && vis[a] == 2)
        {
            cout<<"No"<<endl;
            flag = 1;
            break;
        }
    }
    if(!flag){
        cout<<"Yes"<<endl;
    }
    return 0;
}