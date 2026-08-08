#include<bits/stdc++.h>
// #define if while//???jc
#define N 100005
#define M 22
using namespace std;
char c[N];
int bian[M][M],dui[55],tong[55],tot;
int dp[1<<M],n,yuan,gugugu;
int main(){
	scanf("%s",c);
	n=strlen(c);
	for(int i=0;i<n;++i) tong[c[i]-'a']=1;
	for(int i='a'-'a';i<='z'-'a';++i) if(tong[i]) dui[i]=tot,tot++;//
	for(int i=0;i<n-1;++i){
		if(c[i]==c[i+1]) continue;
		 bian[dui[c[i]-'a']][dui[c[i+1]-'a']]++;
//		 printf("%d %d\n",dui[c[i]],dui[c[i+1]]);
	}
	for(int i=0;i<(1<<tot);++i)
		for(int j=0;j<tot;++j){
			if(i&(1<<j)==0) continue;
			int yuan=i^(1<<j),gugugu=0;
			for(int k=0;k<tot;++k){
				if(yuan&(1<<k)==0) continue;
				gugugu+=bian[k][j];
			}
			dp[i]=max(dp[i],dp[yuan]+gugugu);
		}			
	printf("%d",n-dp[(1<<tot)-1]);	
	return 0;//zkc
}
//mildredree