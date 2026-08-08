#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
struct Edge{
    int from, to, w;
};
struct Graph{
    Edge e[qwe];
    int hd[qwe];
    int cnt = 0;
    void add(int u, int v, int w){
        e[++cnt] = {hd[u], v, w};
        hd[cnt] = u;
    }
} g;
struct KRT{
    int w[qwe];
    int fa[qwe];
} krt;

int fa[qwe];
int fnd(int x){
    if(fa[x] == x){
        return x;
    }
    return fa[x] = fnd(fa[x]);
}

int main(){

}