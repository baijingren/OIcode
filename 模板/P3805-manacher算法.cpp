#include<bits/stdc++.h>
using namespace std;
const int qwe=3e7+5;
int n;
int p[qwe],ans=0;
char s[qwe],a[qwe];
void init(){
    a[0]=a[1]='#';
    // for(int i=2;i<=n*2;i++){
        // a[i]=s[(i<<1)+2];
    // }
    for(int i=1;i<=n;i++){
        a[i*2]=s[i];
        a[i*2+1]='#';
    }
    n=strlen(a);
}
void work(){
    for(int i=1,r=0,mid=0;i<=n;i++){
        if(i<r){//设i关于mid的对称点为j，j=mid+(mid-i)=mid*2-i;
            p[i]=min(p[mid*2-i],p[mid]+mid-i);//寻找回文串的长度，即i关于mid对称点j的回文串长度与以mid为中心，i为其中一个端点的回文串长度
        }
        else{
            p[i]=1;//如果i比当前考虑的右端点大，则长度为1
        }
        while(a[i+p[i]]==a[i-p[i]]){
            p[i]++;
        }
        if(p[i]+i>r){
            r=p[i]+i;
            mid=i;
        }
        if(p[i]>ans){
            ans=p[i];
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>(s+1);
    n=strlen(s+1);
    init();
    // cout<<a<<endl;
    ans=0;
    work();
    cout<<ans-1<<endl;
    return 0;
}