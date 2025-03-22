#include <bits/stdc++.h>
using namespace std;
int t[20];
int main(){
    for(int i = 1; i <= 7; i++){
        int x;
        cin >> x;
        t[x] ++;
    }
    int flag_1 = 0, flag_2 = 0;
    for(int  i = 1; i <= 13; i++){
        if(t[i] >= 3){
            flag_1 ++;
        }
        else if(t[i] == 2){
            flag_2 ++;
        }
    }
    if(flag_1 >= 2 || (flag_1 != 0 && flag_2 != 0)){
        cout << "Yes\n";
        return 0;
    }
    else{
        cout << "No\n";
    }
    return 0;
}