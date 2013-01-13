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
	int m, n;
	scanf("%d", &m);
	
	while(m--)
	{
		scanf("%d", &n);
		int lcm, i, b;
		scanf("%d", &lcm);
		for (i = 1; i < n; ++i)
		{
			scanf("%d", &b);
			lcm = max(lcm, b) / CalcGcd(lcm, b) * min(lcm, b);
		}
		printf("%d\n", lcm);
	}

	return 0;
}
/*
	最小公倍数 = x * y / 最大公约数(x, y)
	最大公约数用辗转相除法求出：gcd(x, y) = gcd(y, x%y)
	lcm = max(lcm, b) / CalcGcd(lcm, b) * min(lcm, b);
	上述代码主要为了防止乘法溢出
*/