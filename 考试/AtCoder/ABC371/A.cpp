#include<bits/stdc++.h>
using namespace std;
char a,b,c;
int main(){
    cin>>a>>b>>c;
    if(a == '<' && c == '<'){
        cout<<'B';
    }
    else if(a == '>' && c == '>'){
        cout<<'B';
    }
    else if(a == '<' && c == '>' && b == '<'){
        cout<<'C';
    }
    else if(a == '<' && c == '>' && b == '>'){
        cout<<'A';
    }
    else if(a == '>' && c == '<' && b == '<'){
        cout<<'A';
    }
    else{
        cout<<'C';
    }
    return 0;
}