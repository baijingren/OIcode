#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int n,cnt=1;
void f(int x){
    if(x==1)
    {
        cout<<" /\\ "<<endl<<"/__\\";
        return;
    }
    f(x-1);
    cout<<endl;
    f(x-1);
    f(x-1);
}
int main(){
    scanf("%d",&n);
    f(n);
    return 0;
}