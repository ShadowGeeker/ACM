/*
	Author: ShadowGeeker
	GitHub: https://github.com/ShadowGeeker/
	Blog:   http://liuke.org/
*/
#include <iostream>
#include <cstdio>
using namespace std;

int CalcGcd(int a, int b)
{
	if (a < b) swap(a, b);
	int tmp = a % b;
	while (tmp != 0)
	{
		a = b;
		b = tmp;
		tmp = a % b;
	}
	
	return b;
}

int main(int argc, char **argv)
{
	int x, y;
	while (EOF != scanf("%d %d", &x, &y))
	{
		int gcd = CalcGcd(x, y);
		printf ("%d\n", x*y/gcd);
	}

	return 0;
}
/*
	最小公倍数 = x * y / 最大公约数(x, y)
	最大公约数用辗转相除法求出：gcd(x, y) = gcd(y, x%y)
*/