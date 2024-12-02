#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int n;

char a[qwe][20];
int f[35][35];

int c(char x){
    return x-'a'+1;
}

int main(){
    cin>>n;
    // memset(f,sizeof(f),0xff);
    for(int i=1;i<=26;i++){
        for(int j=1;j<=26;j++){
            f[i][j]=INT_MIN;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int len = strlen(a[i]);
        int l=c(a[i][0]),r=c(a[i][len-1]);
        for(int j=1;j<=26;j++){
            f[j][r] = max(f[j][r],f[j][l]+len);
        }
        f[l][r] = max(f[l][r],len);
    }
    int ans = 0;
    for(int i=1;i<=26;i++){
        ans=max(ans,f[i][i]);
    }
    cout<<ans<<endl;
}