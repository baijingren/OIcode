#include<bits/stdc++.h>
using namespace std;
const int qwe=3e7+5;
int n;
int ans=0;
string s;
char a[qwe];
int p[qwe];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>s;
    n=s.length();
    a[0]='~';
    for(int i=1;i<=n*2+1;i++){
        if(i%2==1){
            a[i]='#';
        }
        else{
            a[i]=s[i/2-1];
        }
    }
    n=strlen(a);
    for(int i=1,r=0,mid=0;i<=n;i++){
        if(i<r){
            p[i]=min(p[mid*2-i],r-i+1);
        }
        while(a[i-p[i]]==a[i+p[i]]){
            ++p[i];
        }
        if(p[i]+i>r){
            r=p[i]+i-1;
            mid=i;
        }
        if(p[i]>ans){
            ans=p[i];
        }
    }
    cout<<ans-1<<endl;
    return 0;
}