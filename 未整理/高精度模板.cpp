#include<bits/stdc++.h>
using namespace std;
#define kkk(i) this->i
const int qwe=1e6+5;
class NUM{
    public:
        NUM read(){
            
        }
        NUM operator+(const NUM &b){//未解决：带有负数的加法判断并转化为减法（似乎没用）
            int l=max(kkk(len),b.len);
            NUM c;
            c.len=l;
            for(int i=1;i<=l;i++){
                c.s[i]=kkk(s[i])+b.s[i];
                c.s[i+1]=c.s[i]/10;
                c.s[i]%=10;
            }
            if(c.s[len+1]) c.len++;
            return c;
        }
        NUM operator-(const NUM &b){
            int l=1
        }
        NUM operator*(const NUM &b){

        }
        NUM operator/(const int a){

        }
        NUM operator%(const NUM &b){

        }
        bool operator==(const NUM b){
            if(b.len!=kkk(len)) return false;
            for(int i=1;i<=kkk(len);i++){
                if(b.s[i]!=kkk(s[i])) return false;
            }
            return true;
        }
        bool operator<(const NUM b){
            if(b.len>kkk(len)) return false;
        }
        bool operator>(const NUM b){
            if(b.len<kkk(len)) return false;
        }
        void print(NUM x){

        }
        int len,s[qwe];
        bool le0;
};
int main(){
    return 0;
}