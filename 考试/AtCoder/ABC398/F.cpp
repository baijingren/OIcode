#include <bits/stdc++.h>
using namespace std;
const int qwe = 2e6+5;
char c[qwe];
int n;
int main(){
    scanf("%s", c);
    n = strlen(c);
    int i, j;
    for(i = 0, j = n - 1; i < n; i++){
        if(i == j || i > j){
            break;
        }
        if(c[i] == c[j]){
            j--;
        }
        else{
            j = n - 1;
        }
    }
    for(i = i + j - n; i >= 0; i--){
        c[n++] = c[i];
    }
    printf("%s\n", c);
    return 0;
}