#include<bits/stdc++.h>
using namespace std;
int main(){
	int a = 3, b = 0;
	// b = a++;
	// c = a; d = a + 1; a = d; b = c;

	a = a++ + ++a;
	// c = a; d = a + 1; a = d; a += 1; a += c; // gcc result:8
	// c = 1; c += a; d = c; c = d; a = c; c = d; c += a; a = c; c = 1; c += a; a = c; //icc result:9
	cout << a << ' ' << b << endl;
	return 0;
}