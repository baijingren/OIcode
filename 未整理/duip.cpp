#include<bits/stdc++.h>
using namespace std;
int main(){
	for(int i=1;i<=10;i++)
	{
		system("./make");
		system("./p1001");
		system("./right");
		printf("%d: ",i);
		if(system("diff test.out right.out"))
		{
			printf("Wrong Answer\n");
			return 0;
		}
		else
			printf("Accepted\n");
	}
	return 0;
}
