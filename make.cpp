#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("test.in","w",stdout);
	int x,y;
	srand(time(NULL));
	x=rand()%100+900;
	printf("%d\n", x);
	for (int i = 1; i <= x; i++)
	{
		printf("%d ", rand() % 1000);
	}
	return 0;
}
