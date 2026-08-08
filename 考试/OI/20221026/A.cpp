#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,len=1;
double R[qwe];
char s[qwe];
stack<char> st;
stack<double> it;
// double ans;
int main(){
	freopen("resistance.in","r",stdin);
	freopen("resistance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lf",&R[i]);
	}
	// for(int i=1;i<=n;i++){
	// 	cerr<<R[i]<<' ';
	// }
	while(scanf("%s",s+len)!=EOF){
		len=strlen(s+1)+1;
	}
	len-=1;
	for(int i=1;i<=len;i++){
		if(s[i]==')'){
			while(st.top()!='('){
				if(st.top()=='-'){
					double tmp=it.top();it.pop();
					double temp=it.top();it.pop();
					it.push(temp+tmp);
				}
				else{
					double tmp=it.top();it.pop();
					double temp=it.top();it.pop();
					it.push(1.0/(1.0/temp+1.0/tmp));
				}
				st.pop();
			}
			st.pop();
		}
		else if(s[i]>='0' && s[i]<='9'){
			it.push(R[s[i]-'0']);
		}
		else if(s[i]!='R'){
			st.push(s[i]);
		}
	}
	// printf("%s",s+1);
	// ans=it.top();
	printf("%.5lf",it.top());
	return 0;
}