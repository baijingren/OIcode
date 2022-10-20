#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,m;
string a[qwe],b[qwe];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        // scanf("%s",&a[i]);
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    set<string> s;
    for(int i=1;i<=m;i++){
        s.insert(b[i]);
    }
    for(int i=1;i<=n;i++){
        printf("%s\n",s.count(a[i])?"Yes":"No");
    }
}