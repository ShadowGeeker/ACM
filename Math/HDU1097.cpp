/*
	Author: ShadowGeeker
	GitHub: https://github.com/ShadowGeeker/
	Blog:   http://liuke.org/
*/
#include <iostream>
#include <cstdio>
using namespace std;

int GetRightMostNumber(int a, int b)
{
	int res, i, tmp;
	int T[10] = {1, 1, 4, 4, 2, 1, 1, 4, 4, 2};
	
	tmp = a % 10;
	if (T[tmp] == 1) return tmp;
	
	res = 1;
	b = b % T[tmp];
	if (b == 0) b = T[tmp];
	
	for (i = 0; i < b; ++i)
	{
		res *= tmp;
		res %= 10;
	}
	
	return res;
}

int main(int argc, char **argv)
{
	int a, b;
	while (EOF != scanf("%d %d", &a, &b))
	{
		printf("%d\n", GetRightMostNumber(a, b));
	}

	return 0;
}

/*
个位数0-9乘以自身所得个位数的周期：
0           1
1           1
2 4 8 6     4
3 9 7 1     4
4 6         2
5           1
6           1
7 9 3 1     4
8 4 2 6     4
9 1         2
如果n%T为0，那么应该令n=T

这个题就是HDU1061的另一个版本 从a^a到a^b
*/