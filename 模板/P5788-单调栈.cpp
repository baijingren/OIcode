#include<bits/stdc++.h>
using namespace std;
const int qwe=5e6+5;
int n;
int a[qwe],b[qwe];
stack<int> s;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        while(!s.empty() && a[s.top()]<a[i]){
            b[s.top()]=i;
            s.pop();
        }
        s.push(i);
    }
    for(int i=1;i<=n;i++){
        printf("%d ",b[i]);
    }
    return 0;
}