/*
    Author: ShadowGeeker
    GitHub: https://github.com/ShadowGeeker/
    Blog:   http://liuke.org/
*/
#include <iostream>
#include <cstdio>
using namespace std;

__int64 res;
int n, m, num[22];

int GCD(int a, int b)
{
	int r = a % b;
	while (r)
	{
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

__int64 LCM(int a, int b)
{
	__int64 gcd = GCD(a, b);
	return max(a, b) / gcd * min(a, b);
}

void DFS(int seq, int idx, __int64 val)
{
	int i;
	val = LCM(num[idx], val);
	if (seq & 1)
	{
		// odd
		res += (n - 1)/val;
	}
	else
	{
		// even
		res -= (n - 1)/val;
	}
	for (i = idx+1; i < m; ++i)
	{
		DFS(seq+1, i, val);
	}
}

int main(int argc, char **argv)
{
	int i, j;
	
	while (EOF != scanf("%d %d", &n, &m))
	{
		res = 0;
		j = 0;
		for (i = 0; i < m; ++i)
		{
			scanf("%d", &num[j]);
			if (num[j] != 0) ++j;
		}
		m = j;
		for (i = 0; i < m; ++i)
		{
			DFS(1, i, num[i]);
		}
		printf("%I64d\n", res);
	}
	
	return 0;
}
/*
	容斥原理：http://zh.wikipedia.org/wiki/%E6%8E%92%E5%AE%B9%E5%8E%9F%E7%90%86
*/