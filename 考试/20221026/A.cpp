#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,len=1;
int R[qwe];
char s[qwe];
stack<int> st;
int main(){
	freopen("resistance.in","r",stdin);
	freopen("resistance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&R[i]);
	}
	while(scanf("%s",s+len)!=EOF){
		len=strlen(s+1)+1;
	}
	len-=1;
	for(int i=1;i<=len;i++){
		if(s[i]=='('){
			st.push(
		}
	}
	printf("%s",s+1);
	return 0;
}