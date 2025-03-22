#include <iostream>
using namespace std;
const int N = 8;
int main()
{
	int s[N] = {3,
				1,
				5,
				7,
				9,
				2,
				4,
				6};
	func(s, 0, N - 1);
	return 0;
}
void print(int *s, int N)
{
	for (int i = 0; i < N; i++)
		cout << s[i] << " ";
}