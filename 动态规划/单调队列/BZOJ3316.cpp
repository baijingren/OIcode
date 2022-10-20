#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,L,R;
int a[qwe];
bool chk(int x){

}
int main(){
    scanf("%d%d%d",&n,&L,&R);
    double l=0.0,r=0.0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i+n]=a[i];
        l=min(l,(double)a[i]);
        r=max(r,(double)a[i]);
    }
    while(l<r){
        int mid=(l+r)/2;
        if(chk(mid)){
            l=mid;
        }
        else{
            r=mid;
        }
    }
}