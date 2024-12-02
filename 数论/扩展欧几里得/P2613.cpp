#include<bits/stdc++.h>
using namespace std;
const int mod=19260817;
int a,b;
int read(){
    int ans=0,y=1;
    char c=getchar();
    while(c<'0' || c>'9'){
        if(c=='-'){
            y=-1;
        }
        c=getchar();
    }
    while(c>='0' && c<='9'){
        ans=(ans*10+c-'0')%mod;
        c=getchar();
    }
    return ans;
}
void exgcd(int &x,int &y,int a,int b){
    if(b==0){
        x=1;
        y=0;
        return;
    }
    exgcd(x,y,b,a%b);
    int tmp=x;
    x=y;
    y=tmp-a/b*y;
    return;
}
int main(){
    a=read();
    b=read();
    if(b==0){
        cout<<"Angry!\n";
    }
    else{
        int x=0,y=0;
        exgcd(x,y,b,mod);
        x=(x%mod+mod)%mod;
        cout<<(1ll*a*x%mod)<<'\n';
    }
    return 0;
}