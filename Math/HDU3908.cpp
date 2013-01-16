/*
	Author: ShadowGeeker
	GitHub: https://github.com/ShadowGeeker/
	Blog:   http://liuke.org/
*/
#include <iostream>
#include <cstdio>
using namespace std;

const int g_nMaxNum = 810;

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

int main(int argc, char **argv)
{
	int t, n, i, j;
	int num[g_nMaxNum];
	
	scanf("%d", &t);
	while (t--)
	{
		int pnum[g_nMaxNum] = {0}, count;
		scanf("%d", &n);
		for (i = 0; i < n; ++i)
		{
			scanf("%d", &num[i]);
		}
		count = 0;
		for (i = 0; i < n; ++i)
		{
			for (j = i + 1; j < n; ++j)
			{
				if (GCD(num[i], num[j]) == 1)
				{
					pnum[i]++;
					pnum[j]++;
				}
			}
		}
		for (i = 0; i < n; ++i)
		{
			count += pnum[i]*(n - 1 - pnum[i]);
		}
		int sum = n*(n-1)*(n-2)/6;
		sum -= count/2;
		printf("%d\n", sum);
	}

	return 0;
}
/*
	总的可能的个数C(n,3)减去不满足条件的个数
	不满足：对于a[i]，找出与a[i]互素的数的个数，
	以及不互素的数的个数，相乘就是不满足条件的数了
*/