#include<bits/stdc++.h>
using namespace std;
int hd[1008],hdcnt[1008],inq[1008],dis[1008];
struct edge{
	int ed,val,nxt;
}e[10008];
int ecnt;
void add(int st,int ed,int val){
	ecnt++;
	e[ecnt].ed=ed;
	e[ecnt].val=val;
	e[ecnt].nxt=hd[st];
	hd[st]=ecnt;
}
bool spfa(int s);
int n,m;
int main(){
	int ans;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int st,ed,val;
		scanf("%d%d%d",&st,&ed,&val);
		add(st,ed,val);
	}
	if(spfa(1)){
		printf("Forever love");
		return 0;
	}else{
		ans=dis[n];
	}
	if(spfa(n)){
		printf("Forever love");
		return 0;
	}else{
		ans=ans<dis[1]?ans:dis[1];
		printf("%d",ans);
	}
	return 0;
}
bool spfa(int s){
	queue<int> myq;
	memset(dis,0x3f,sizeof(dis));
	memset(hdcnt,0,sizeof(hdcnt));
	memset(inq,0,sizeof(inq));
	dis[s]=0;
	myq.push(s);
	inq[s]=1;
	while(!myq.empty()){
		int cur=myq.front();
		myq.pop();
		inq[cur]=0;
		for(int i=hd[cur];i;i=e[i].nxt){
			int en,ev;
			en=e[i].ed;
			ev=e[i].val;
			if(dis[en]>dis[cur]-ev){
				dis[en]=dis[cur]-ev;
				hdcnt[en]++;
				if(hdcnt[en]>n-1){
					return true;
				}
				if(!inq[en]){
					myq.push(en);
					inq[en]=1;
				}
			}
		}
	}
	return false;
}
