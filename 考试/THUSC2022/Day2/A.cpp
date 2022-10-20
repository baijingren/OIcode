#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
string a,k,out_put;
vector<string> s;
bool read(string &a){
    char c=getchar();
    while(c=='\ ' || c=='\t'){
        c=getchar();
    }
    while(c!=EOF){
        if(c=='\n' || c=='\r'){
            break;
        }
        a.push_back(c);
        c=getchar();
    }
    if(c==EOF){
        return 0;
    }
    return 1;
}
void print(){
    if(out_put.length()==0){
        return;
    }
    int n=s.size();
    while((out_put[n-1]=='\ ' || out_put[n-1]=='\t' || out_put[n-1]=='\r' || out_put[n-1]=='\n')){
        n--;
    }
    for(int i=0;i<n-1;i++){
        cout<<s[i]<<'>';
    }
    cout<<s[n-1]<<':'<<out_put<<endl;
    out_put.clear();
}
bool in_tags=0,still_in_tags=0,no_char_exist=0,in_end_tags=0,is_an_image=0;
int main(){
    freopen("A1.in.html","r",stdin);
    while(read(a)){
        int n=a.length();
        for(int i=0;i<n;i++){
            if(in_tags){
                if(a[i]=='>' || a[i]=='\ '){
                    // in_tags=0;
                    k.erase(0,1);
                    if(in_end_tags){
                        print();
                        s.pop_back();
                    }
                    else
                        if(!is_an_image && !still_in_tags)
                            s.push_back(k);
                    if(a[i]=='>'){
                        in_tags=0;
                        in_end_tags=0;
                        still_in_tags=0;
                        is_an_image=0;
                    }
                    else if(a[i]=='\ '){
                        still_in_tags=1;
                    }
                }
                else{
                    k.push_back(a[i]);
                    if(a[i]=='/' && a[i-1] == '<'){
                        in_end_tags=1;
                        k.pop_back();
                    }
                    if(k=="<style"|| k=="<script"){
                        no_char_exist=1;
                    }
                    if(k=="<img"){
                        is_an_image=1;
                    }
                }
            }
            else{
                if(a[i]=='<'){
                    k.clear();
                    k.push_back(a[i]);
                    in_tags=1;
                }
                else{
                    if(no_char_exist){
                        continue;
                    }
                    else{
                        if(out_put.empty() && (a[i]=='\ ' || a[i]=='\t' || a[i]=='\r' || a[i]=='\n')){
                            continue;
                        }
                        else{
                            out_put.push_back(a[i]);
                        }
                    }
                }
            }
        }
        a.clear();
    }
    return 0;
}