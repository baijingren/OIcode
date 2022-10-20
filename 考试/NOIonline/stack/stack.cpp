#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,q;
int f[qwe];
bool v[qwe];
struct Node{
    int a,b;
} a[qwe],p[qwe];
stack<Node> s;
int main(){
    freopen("stack.in","r",stdin);
    freopen("stack.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].a);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].b);
    }
    s.push(a[1]);
    f[1]=1;
    v[1]=1;
    for(int i=2;i<=n;i++){
        // if(s.top)
        f[i]=f[i-1];
        while(!s.empty() && (a[i].b >= s.top().b || a[i].a == s.top().a)){
            s.pop();
        }
        s.push(a[i]);
        if(s.size()==1){
            f[i]=f[i-1]+1;
            v[i]=1;
        }
        // else{
        // }
    }
    // for(int i=1;i<=n;i++){
    //     printf("%d ",f[i]);
    // }
    // cout<<endl;
    for(int i=1;i<=q;i++){
        int l,r,ans=0;
        scanf("%d%d",&l,&r);
        int _f=0;
        while(!s.empty()){
            s.pop();
        }
        s.push(a[l]);
        ans++;
        if(v[l]){
            _f=l;
            // break;
        }
        // cout<<s.size()<<' ';
        for(int j=l+1;j<=r;j++){
            while(!s.empty() && (a[j].b >= s.top().b || a[j].a == s.top().a)){
                s.pop();
            }
            s.push(a[j]);
            if(s.size()==1){
                ans++;
                // f[i]=f[i-1]+1;
                // v[i]=1;
            }
            if(v[j]){
                _f=j;
                break;
            }
            // cout<<s.size()<<' ';
        }
        if(_f){
            int ff=0;
            for(int j=r;j>=l;j--){
                if(v[j]){
                    ff=j;
                    break;
                }
            }
            // cout<<ff<<' '<<_f<<'d'<<endl;
            ans+=(f[ff]-f[_f]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
in:
10 4
3 1 3 1 2 3 3 2 1 1
10 10 2 9 7 5 4 7 6 1
1 4
7 8
7 10
1 8
out:
3
2
2
3
*/